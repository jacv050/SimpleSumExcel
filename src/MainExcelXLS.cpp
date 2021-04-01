#include "MainExcelXLS.hpp"  

MainExcelXLS* MainExcelXLS::mainExcelXLS = NULL;

MainExcelXLS::MainExcelXLS()
{
	
}
	
MainExcelXLS::~MainExcelXLS()
{
	
}

void MainExcelXLS::initMainExcelXLS(){
    if(mainExcelXLS == NULL){
        MainExcelXLS::mainExcelXLS = new MainExcelXLS();
    }
}

void MainExcelXLS::splitCell(const std::string& cell, std::string& row, std::string& col){
    int i=0;
    while(i<cell.size() && cell[i] >= 'a' && cell[i] <= 'z'){
        col.append(1,cell[i]);
        ++i;
    }
    while(i<cell.size()){
        row.append(1,cell[i]);
        ++i;
    }
}

//Date en format year/month/day
int MainExcelXLS::calculateBalance(const std::string& date, const std::string& excelsFolder){
    const std::vector< std::string > foldersPlaces = mainExcelXLS->settings.getFoldersPlaces();
    const std::string credentialCell = mainExcelXLS->settings.getCredentialCell();
    const std::string totalCell = mainExcelXLS->settings.getTotalCell();
    const std::vector< std::string > specialCell = mainExcelXLS->settings.getSpecialSheetCells();

    //TotalCell row and col
    std::string tcrow_s, tccol_s; int tcrow_i, tccol_i;
    splitCell(totalCell, tcrow_s, tccol_s);
    tcrow_i = atoi(tcrow_s.c_str()); tccol_i = utils::charExcelToNumber(tccol_s);
    //Credential cell row and col
    std::string cccrow_s, cccol_s; int cccrow_i, cccol_i;
    splitCell(credentialCell, cccrow_s, cccol_s);
    cccrow_i = atoi(cccrow_s.c_str()); cccol_i = utils::charExcelToNumber(cccol_s);
    //Date to calculate balance
    boost::gregorian::date calcDate(boost::gregorian::from_simple_string(date));
    //RootDir where places are. Absolute path whera the corresponding excels. 

    std::string credentialCellValue;
    int output = 0;
    boost::filesystem::directory_iterator end_itr;
    for(boost::filesystem::directory_iterator itrPlaces(excelsFolder); itrPlaces != end_itr; ++itrPlaces){
        if(boost::filesystem::is_directory(itrPlaces->path())){
            for(boost::filesystem::directory_iterator itrExcels(itrPlaces->path()); itrExcels != end_itr; ++itrExcels){
                //Check xls files
                if(boost::filesystem::extension(itrExcels->path())==".xls"){
                    //ExcelFormat::BasicExcel xls(dir.c_str();
                    std::cout << std::endl;
                }
            }
        }
    }

    //Read Credential Cell values
    std::string id, limit; int i=0;
    utils::lineParser(credentialCellValue, id, i, '-');
    utils::lineParser(credentialCellValue, limit, i, (char)128);//128 = €

    return output;
}