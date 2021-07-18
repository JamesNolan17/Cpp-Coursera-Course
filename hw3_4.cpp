#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
    //Part 1: Data fetch + initialization
    int exp_number;
    cin >> exp_number;
    int heart_red[exp_number];        //0       1      2       3    4
    int heart_blue[exp_number];
    int heart_req[exp_number][5]; //dragon 、ninja、iceman、lion、wolf
    int heart;
    for (int i = 0; i < exp_number; i++){
        cin >> heart;
        heart_red[i] = heart;
        heart_blue[i] = heart;
        for (int j = 0; j < 5; j++) cin >> heart_req[i][j];
    }


    //Part 2: Per experiment
    for (int current_case_number = 0; current_case_number < exp_number; current_case_number++){
        //Sub-Part 1: Generate warriors.
        int timestamp = 0;
                                    //0       1    2     3      4
        int red_first_choice = 0;   //iceman、lion、wolf、ninja、dragon
        int blue_first_choice = 0;  //lion、dragon、ninja、iceman、wolf
        int red_warrier_number[5] = {0};
        int blue_warrier_number[5] = {0};
        bool red_end = false;
        bool blue_end = false;
        int red_no = 0;
        int blue_no = 0;
        //int min_heart_req = *min_element(heart_req[current_case_number], heart_req[current_case_number] + 5);
        int min_heart_req = heart_req[current_case_number][0];
        for (int i = 0; i < 5; i++){
            if (heart_req[current_case_number][i] < min_heart_req) min_heart_req = heart_req[current_case_number][i];
        }

        //1. output case number.
        cout << "Case:" << current_case_number+1 << endl;
        while (!red_end || !blue_end){
            //Start of a round
            bool red_current_end = false;
            bool blue_current_end = false;
            stringstream ss;
            ss << setw(3) << setfill('0') << timestamp;
            string ts_string;
            ss >> ts_string;
            //Red part
            if (heart_red[current_case_number] >= min_heart_req){
                //red_first_choice part
                int warrior_in_list;
                int warrior_case;
                string warrior_name;
                while (!red_current_end){
                    switch (red_first_choice % 5){
                        case 0:
                            warrior_in_list = 2;
                            warrior_case = 0;
                            warrior_name = "iceman";
                            if (heart_red[current_case_number] >= heart_req[current_case_number][warrior_in_list]) {
                                red_current_end = true;
                                break;
                            }else{
                                red_first_choice++;
                            }
                        case 1:
                            warrior_in_list = 3;
                            warrior_case = 1;
                            warrior_name = "lion";
                            if (heart_red[current_case_number] >= heart_req[current_case_number][warrior_in_list]) {
                                red_current_end = true;
                                break;
                            }else{
                                red_first_choice++;
                            }
                        case 2:
                            warrior_in_list = 4;
                            warrior_case = 2;
                            warrior_name = "wolf";
                            if (heart_red[current_case_number] >= heart_req[current_case_number][warrior_in_list]) {
                                red_current_end = true;
                                break;
                            }else{
                                red_first_choice++;
                            }
                        case 3:
                            warrior_in_list = 1;
                            warrior_case = 3;
                            warrior_name = "ninja";
                            if (heart_red[current_case_number] >= heart_req[current_case_number][warrior_in_list]) {
                                red_current_end = true;
                                break;
                            }else{
                                red_first_choice++;
                            }
                        case 4:
                            warrior_in_list = 0;
                            warrior_case = 4;
                            warrior_name = "dragon";
                            if (heart_red[current_case_number] >= heart_req[current_case_number][warrior_in_list]) {
                                red_current_end = true;
                                break;
                            }else{
                                red_first_choice++;
                            }
                    }
                }
                //Modify data when red is done
                heart_red[current_case_number] -= heart_req[current_case_number][warrior_in_list];
                red_first_choice++;
                red_no++;
                red_warrier_number[warrior_case]++;
                //Print info
                cout << ts_string << " red " << warrior_name << " " << red_no << " born with strength ";
                cout << heart_req[current_case_number][warrior_in_list];
                cout << "," << red_warrier_number[warrior_case] << " " << warrior_name;
                cout << " in red headquarter" << endl;
            }else if (!red_end) {
                    cout << ts_string << " red headquarter stops making warriors" << endl;
                    red_end = true;
            }

            //Blue part
            if (heart_blue[current_case_number] >= min_heart_req){
                //blue_first_choice part
                int warrior_in_list;
                int warrior_case;
                string warrior_name;
                while (!blue_current_end){
                    switch (blue_first_choice % 5){
                        case 0:
                            warrior_in_list = 3;
                            warrior_case = 0;
                            warrior_name = "lion";
                            if (heart_blue[current_case_number] >= heart_req[current_case_number][warrior_in_list]) {
                                blue_current_end = true;
                                break;
                            }else{
                                blue_first_choice++;
                            }
                        case 1:
                            warrior_in_list = 0;
                            warrior_case = 1;
                            warrior_name = "dragon";
                            if (heart_blue[current_case_number] >= heart_req[current_case_number][warrior_in_list]) {
                                blue_current_end = true;
                                break;
                            }else{
                                blue_first_choice++;
                            }
                        case 2:
                            warrior_in_list = 1;
                            warrior_case = 2;
                            warrior_name = "ninja";
                            if (heart_blue[current_case_number] >= heart_req[current_case_number][warrior_in_list]) {
                                blue_current_end = true;
                                break;
                            }else{
                                blue_first_choice++;
                            }
                        case 3:
                            warrior_in_list = 2;
                            warrior_case = 3;
                            warrior_name = "iceman";
                            if (heart_blue[current_case_number] >= heart_req[current_case_number][warrior_in_list]) {
                                blue_current_end = true;
                                break;
                            }else{
                                blue_first_choice++;
                            }
                        case 4:
                            warrior_in_list = 4;
                            warrior_case = 4;
                            warrior_name = "wolf";
                            if (heart_blue[current_case_number] >= heart_req[current_case_number][warrior_in_list]) {
                                blue_current_end = true;
                                break;
                            }else{
                                blue_first_choice++;
                            }
                    }
                }
                //Modify data when blue is done
                heart_blue[current_case_number] -= heart_req[current_case_number][warrior_in_list];
                blue_first_choice++;
                blue_no++;
                blue_warrier_number[warrior_case]++;
                //Print info
                cout << ts_string << " blue " << warrior_name << " " << blue_no << " born with strength ";
                cout << heart_req[current_case_number][warrior_in_list];
                cout << "," << blue_warrier_number[warrior_case] << " " << warrior_name;
                cout << " in blue headquarter" << endl;
            }else if (!blue_end) {
                cout << ts_string << " blue headquarter stops making warriors" << endl;
                blue_end = true;
            }
            //Modify values for the next round.
            timestamp++;
        }
    }
}