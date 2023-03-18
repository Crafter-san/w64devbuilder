#include <processthreadsapi.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
std::vector<std::string> customSplit(std::string str, char separator) {
	std::vector<std::string> strings;
	int startIndex = 0, endIndex = 0;
	for (int i = 0; i <= str.size(); i++) {

		// If we reached the end of the word or the end of the input.
		if (str[i] == separator || i == str.size()) {
			endIndex = i;
			std::string temp;
			temp.append(str, startIndex, endIndex - startIndex);
			strings.push_back(temp);
			startIndex = endIndex + 1;
		}
	}
	return strings;
}
std::vector<std::string> rip_file(std::string path) {
	int i = 0;
	std::vector<std::string> lines;
	std::ifstream read_file(path);
	std::string myText;
	while (std::getline(read_file, myText)) {
		lines.push_back(myText);
		i++;
	}
	read_file.close();
	return lines;
}/*
std::char string_to_char(std::string str) {
	char char_str = "";
	for (int i = 0; i < string.length(); i++) {
		char_str += str[i];
	}
	return char_str;
}*/
std::string base_command = "g++ ";
std::string input_files = "";
std::string libs = "";
std::string libraries = "";
std::string includes = "";
std::string output_file = "-o a.out ";
std::string compress = "-Os -s";
std::string output = "a.out";
int build_delay = 10000;
int run_delay = 10000;
void process_cmd(std::vector<std::string> command) {
	if (command[0] == "output") {
		output_file = "-o " + command[1] + " ";
		output = command[1];
	}
	else if (command[0] == "libs") libs += "-l" + command[1] + " ";
	else if (command[0] == "libraries") libraries += "-L" + command[1] + " ";
	else if (command[0] == "includes") includes += "-I" + command[1] + " ";
	else if (command[0] == "input") input_files += command[1] + " ";
	else if (command[0] == "delay_after_build") build_delay = std::stoi(command[1]);
	else if (command[0] == "delay_after_run") run_delay = std::stoi(command[1]);
	else if (command[0] == "base_build") base_command = command[1] + " ";
};
int main(int argc, char* argv[]) {
	_PROCESS_INFORMATION processInformation;
	BOOL creationResult;
	std::vector<std::string> lines;
	if (argc == 1) return 0;
	lines = rip_file(argv[1]);
	char SPACE = ' ';
	for (int i = 0; i < lines.size(); i++) {
		std::vector<std::string> line = customSplit(lines[i], SPACE);
		process_cmd(line);
	}
	base_command += input_files + libraries + includes + libs + output_file + compress;
	//const char * com = command.c_str();
	//char test[] = { com };
	std::cout << std::endl << base_command << std::endl;
	STARTUPINFO siStartInfo = {};
	siStartInfo.cb = sizeof(STARTUPINFO);
	siStartInfo.hStdError = GetStdHandle(STD_OUTPUT_HANDLE);
	siStartInfo.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	siStartInfo.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
	siStartInfo.dwFlags |= STARTF_USESTDHANDLES;
	creationResult = CreateProcessA(NULL, base_command.data(), NULL, NULL, true, 0, NULL, NULL, &siStartInfo, &processInformation);
	WaitForSingleObject(processInformation.hProcess, INFINITE);
	Sleep(build_delay);
	
	creationResult = CreateProcessA(NULL, output.data(), NULL, NULL, true, 0, NULL, NULL, &siStartInfo, &processInformation);
	WaitForSingleObject(processInformation.hProcess, INFINITE);
	Sleep(run_delay);
	return 0;
};
