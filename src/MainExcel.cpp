#include "MainExcel.hpp"  

MainExcel* MainExcel::mainExcelXLS = NULL;

MainExcel::MainExcel()
{
	
}
	
MainExcel::~MainExcel()
{
	
}

void MainExcel::initMainExcel(){
    if(mainExcelXLS == NULL){
        MainExcel::mainExcelXLS = new MainExcel();
    }
}

void MainExcel::processCredential(const std::wstring& cred, std::wstring& id, std::wstring& limit){
    int i=0;
    utils::lineParser(cred, id, i, '-');
    utils::lineParser(cred, limit, i, '-');//128 = €
}

std::string MainExcel::getMonthFolder(){
    return mainExcelXLS->settings.getMonthFolder();
}

void MainExcel::saveMonthFolder(const std::string& monthFolder){
    mainExcelXLS->settings.saveMonthFolder(monthFolder);
}

int MainExcel::getSheetIndex(const std::string& limit){
    const std::vector< std::string > workSheets = mainExcelXLS->settings.getWorkSheets();
    for(int i=0; i<workSheets.size(); ++i){
        if(workSheets[i] == limit)
            return i;
    }
    return -1;
}

boost::posix_time::ptime MainExcel::datetime_ole_to_posix(long ole_dt){
  static const boost::gregorian::date ole_zero(1899,12,30);

  boost::gregorian::days d(ole_dt);
  boost::posix_time::ptime pt(ole_zero + d);

  ole_dt -= d.days();
  ole_dt *= 24 * 60 * 60 * 1000;

  return pt + boost::posix_time::milliseconds(std::abs(ole_dt));
}

//Date en format year/month/day
double MainExcel::calculateBalance(const std::string& date, const std::string& excelsFolder){
    const std::vector< std::string > foldersPlaces = mainExcelXLS->settings.getFoldersPlaces();
    const std::vector< std::string > credentialCell = mainExcelXLS->settings.getCredentialCell();
    const std::string totalCell = mainExcelXLS->settings.getTotalCell();
    const std::vector< std::string > specialCell = mainExcelXLS->settings.getSpecialSheetCells();
    //const std::vector< std::string > workSheets = mainExcelXLS->settings.getWorkSheets();
    const std::vector< std::string > dateCell = mainExcelXLS->settings.getDateCell();

    //Date cell row and col
    int dtrow_i, dtcol_i;
    utils::excelToIndex(dateCell[1], dtrow_i, dtcol_i);
    //SpecialCell row and col
    int sprow_i, spcol_i;
    utils::excelToIndex(specialCell[1], sprow_i, spcol_i);
    //TotalCell row and col
    int tcrow_i, tccol_i;
    utils::excelToIndex(totalCell, tcrow_i, tccol_i);
    //Credential cell row and col
    int ccrow_i, cccol_i;
    utils::excelToIndex(credentialCell[1], ccrow_i, cccol_i);
    //Date to calculate balance
    boost::gregorian::date calcDate(boost::gregorian::from_simple_string(date));
    //RootDir where places are. Absolute path whera the corresponding excels. 

    double output = 0;
    double output_nospecial = 0;
    boost::filesystem::directory_iterator end_itr;
    for(boost::filesystem::directory_iterator itrPlaces(excelsFolder); itrPlaces != end_itr; ++itrPlaces){
        if(boost::filesystem::is_directory(itrPlaces->path())){
            for(boost::filesystem::directory_iterator itrExcels(itrPlaces->path()); itrExcels != end_itr; ++itrExcels){
                //Check xls files
                if(boost::filesystem::extension(itrExcels->path())==".xls"){
                    ExcelFormat::BasicExcel wb(itrExcels->path().string().c_str());
                    ExcelFormat::BasicExcelWorksheet* ws = wb.GetWorksheet(dateCell[0].c_str());
                    ExcelFormat::XLSFormatManager fmt_mgr(wb);
                    //Get date cell value
                    double dateCellValue = ws->Cell(dtrow_i, dtcol_i)->GetDouble();
                    boost::posix_time::ptime preadDate = datetime_ole_to_posix((long)dateCellValue); //boost::posix_time::to_simple_string(readDate);
                    boost::posix_time::ptime pcalcDate = boost::posix_time::ptime(calcDate);

                    if(preadDate == pcalcDate){
                        //Get special cell value SI/NO
                        ws = wb.GetWorksheet(specialCell[0].c_str());
                        std::string specialCellValue = ws->Cell(sprow_i, spcol_i)->GetString();
                        utils::tolower(specialCellValue);
                        
                        //Get credential cell value
                        ws = wb.GetWorksheet(credentialCell[0].c_str());
                        std::wstring credentialCellValue = ws->Cell(ccrow_i, cccol_i)->GetWString();
                        //Get id and limit from credential cellvalue
                        std::wstring id, limit;
                        processCredential(credentialCellValue, id, limit);
                        //Get total value
                        ws = wb.GetWorksheet(limit.c_str());

                        double totalValue = ws->Cell(tcrow_i, tccol_i)->GetDouble();
                        output += totalValue;
                        if(specialCellValue != "si")
                            output_nospecial += totalValue;
                    }

                }
            }
        }
    }

    return output;
}