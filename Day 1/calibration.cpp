#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int line_value(const std::string& line){

    std::vector<std::string> substring_digits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::string> subchar_digits = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    std::vector<std::vector<int> > digits; // containing a pair: position in line and digit itself
    int value = 0;

    //Finding digits that are written as words
    for (auto i = 0; i < substring_digits.size(); i++){

        std::string line_copy = line;
        int found_pos_original = line.find(substring_digits[i]);
        int found_pos_in_copy = found_pos_original;
        int counter_of_words = 0;

        while (found_pos_in_copy != std::string::npos){
            counter_of_words++;
            std::vector<int> digit{found_pos_original, i+1};
            digits.push_back(digit);
            line_copy.erase(found_pos_in_copy, substring_digits[i].length());
            if (line_copy.find(substring_digits[i]) != std::string::npos){
                found_pos_original = line_copy.find(substring_digits[i]) + substring_digits[i].length() * counter_of_words;
                found_pos_in_copy = line_copy.find(substring_digits[i]);
            }
            else{
                break;
            }
        }
    }
    // Finding digits that are written as numbers
    for (auto i = 0; i < subchar_digits.size(); i++){

        std::string line_copy = line;
        int found_pos_original = line.find(subchar_digits[i]);
        int found_pos_in_copy = found_pos_original;
        int counter_of_digits = 0;

        while (found_pos_in_copy != std::string::npos){
            counter_of_digits++;
            std::vector<int> digit{found_pos_original, i+1};
            digits.push_back(digit);
            line_copy.erase(found_pos_in_copy, subchar_digits[i].length());
            if (line_copy.find(subchar_digits[i]) != std::string::npos){
                found_pos_original = line_copy.find(subchar_digits[i]) + subchar_digits[i].length() * counter_of_digits;
                found_pos_in_copy = line_copy.find(subchar_digits[i]);
            }
            else{
                break;
            }
        }
    }

    // OLD VERSION FROM PUZZLE №1
    // for (auto element: line){
    //     if((int)element >= 48 and (int)element <= 57){
    //         int int_element = element - '0';
    //         int position = line.find(element);
    //         std::vector<int> digit = {position, int_element};
    //         digits.push_back(digit);
    //     }
    // }


    //Calculating the first and last digit and constructing a calibration value
    std::sort(digits.begin(), digits.end());

    if (sizeof(digits) > 0){
        value = value + digits[0][1] * 10 + digits[digits.size()-1][1];
    }
    return value;
}

int main(){
    int calibration_value = 0;

    std::fstream input_file;
    input_file.open("input.txt", std::ios::in); //input2.txt was used to look through some tests
    if (input_file.is_open()){ //checking whether the file is open
        std::string line;
        while(getline(input_file, line)){ //read data from file object and put it into string.
            auto LV = line_value(line);
            std::cout << line << std::endl;
            std::cout << "From this line I receive a CL = " << LV;
            calibration_value = calibration_value + LV;
            std::cout << "\nThus, current calibration value = " << calibration_value << std::endl;
            std::cout << std::endl;
      }
      input_file.close(); //close the file object.
   }

    std::cout << "Finally CL = " << calibration_value << std::endl;
    return 0;
}