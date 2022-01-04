/**
 * This program will parse wic string into readable form
 * 
 */

// Header Files and usings =========================================================
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

//==================================================================================
class WicFiles {
public:
    void display_e3(string claim);
    void display_d4(string claim);
    void display_z1(string claim);
};

/**
 * @brief display_e3(string claim)
 * 
 * @param claim: Type of wic file to use for parsing
 */

void WicFiles::display_e3(string claim)
{
    vector<string> addenda_record(11);

    // Record identification code
    addenda_record[0] = claim.substr(0,2);
    // Record sequence number
    addenda_record[1] = claim.substr(2,6);
    // Addenda sequence number
    addenda_record[2] = claim.substr(8,3);
    // Category Code
    addenda_record[3] = claim.substr(11,2);
    // Sub-category code
    addenda_record[4] = claim.substr(13,3);
    // Units
    addenda_record[5] = claim.substr(16,5);
    // UPC/PLU data
    addenda_record[6] = claim.substr(21, 17);
    // Purchase quantity
    addenda_record[7] = claim.substr(38,5);
    // Claim Price
    addenda_record[8] = claim.substr(43,9);
    // UPC/PLU data length
    addenda_record[9] = claim.substr(52,2);
    // Amount, item discount
    addenda_record[10] = claim.substr(54,12);

    cout << "Record identification code: " << addenda_record[0] << endl;
    cout << "Record sequence number: " << addenda_record[1] << endl;
    cout << "Addenda sequence number:" << addenda_record[2] << endl;
    cout << "Category code: " << addenda_record[3] << endl;
    cout << "Sub-Category code: " << addenda_record[4] << endl;
    cout << "Units: " << addenda_record[5] << endl;
    cout << "UPC/PLU data: " << addenda_record[6] << endl;
    cout << "Purchase quantity: " << addenda_record[7] << endl;
    cout << "Claim price: " << addenda_record[8] << endl;
    cout << "UPC/PLU data length: " << addenda_record[9] << endl;
    cout << "Amount, Item Discount: " << addenda_record[10] << endl;
    cout << "===============================================================\n";   

}


void WicFiles::display_z1(string claim)
{
    vector<string> trailer_record(9);
    //Record identification code
    trailer_record[0] = claim.substr(0,2);
    // Record sequence number
    trailer_record[1] = claim.substr(2,6);
    // File create date
    trailer_record[2] = claim.substr(8,8);
    // File create time
    trailer_record[3] = claim.substr(16,6);
    // File format version
    trailer_record[4] = claim.substr(22,2);
    // Count, detail records
    trailer_record[5] = claim.substr(24,7);
    // Date, claim
    trailer_record[6] = claim.substr(31,8);
    // Amount, claimed total
    trailer_record[7] = claim.substr(39,7);
    // Amount, discount total
    trailer_record[8] = claim.substr(51,12);

    cout << "Record identification code: " << trailer_record[0] << endl;
    cout << "Record sequence number: " << trailer_record[1] << endl;
    cout << "File create date: " << trailer_record[2] << endl;
    cout << "File create time: " << trailer_record[3] << endl;
    cout << "File format version: " << trailer_record[4] << endl;
    cout << "Count, detail records: " << trailer_record[5] << endl;
    cout << "Date, claim: " << trailer_record[6] << endl;
    cout << "Amount, claimed total: " << trailer_record[7] << endl;
    cout << "Amount, discount total: " << trailer_record[8]<< endl;

}

// Main function ==============================================================

int main()
{
    cout << "Processing WIC information ...." << endl;
    WicFiles wic_obj;
    //string compare = "E30000090121600000200000000729456110300020000000071812000000000000";
    string compare = "Z10000152021111906352004000001320211119000000054329000000001902";
    // "D400001412301950        1950           160006103582102673787009700000000002398009196000000000020211118213148510111111334000000004159       Fresh Grocer 1000 Easton Rd Wyncote                                                19095     PA                                                                                                           001293992109100718202111010000000000008101008204427b86448304000000358404ecd9988e                                                         0050";

    /* Compare holds type of wic file to analyze */
    if (compare.substr(0,2) == "E3")
    {
        cout << "Begin display_e3() ......................." << endl;
        wic_obj.display_e3(compare);
    }
    else if (compare.substr(0,2) == "D4")
    {
        cout << "Begin display_d4() ..." << endl;
        //display_d4(compare);
    }
    else if (compare.substr(0,2) == "Z1")
    {
        cout << "Begin display_z1() ..." << endl;
        wic_obj.display_z1(compare);
    }

    cout << "----------------------------------------------" << endl;


    return 0;
}