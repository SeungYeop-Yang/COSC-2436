/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 * COSC 2436 Programming Fundamentals III
 *
 * Lab 2: "Stack"
 *
 * You will submit the following:
 *
 * All of your program source (.cpp) and header (.h) files only, compressed
 * into a zip file. There should be 6 files:
 *  - StackInterface.h,
 *  - Node.h,
 *  - Node.cpp,
 *  - LinkedStack.h,
 *  - LinkedStack.cpp,
 *  - lab2_SeungYeop_Yang.cpp
 *
 * You will write a program to determine if the punctuation in a C++ for-loop
 * is correct using a stack. You will be checking for correct punctuation only;
 * you just skip over the rest of the characters. You will be checking for the
 * following:
 *
 *  - Loop heading with the three parts with semi-colons and in parentheses:
 *    for (initialization; test; update) with no semi-colon at the end
 *  - Loop body having open and close curly braces if there is more than one
 *    statement in the block
 *  - Semi-colon at the end of each line in the block
 *
 * You will use the Link-based implmenetation of the ADT Stack provided with
 * the assignment. This ADT was covered in Chapter 7. The files are attached to
 * this assignment. There is no reason to modify any of these five files.
 *  - StackInterface.h,
 *  - Node.h,
 *  - Node.cpp,
 *  - LinkedStack.h,
 *  - LinkedStack.cpp
 *
 * You do not need to have the 'peek' method throw an exception if the stack is
 * empty - you can leae that code as-is in the 'LinkedStack' files.
 *
 * You will get the input to test from a text file. The file will contain the
 * for loop code to check as one continuous string - not on separate lines as
 * you would find it in a C++ source code file.
 *
 * Your main should ask the user for the name of the input file. Your main will
 * open the file and if it opened correctly, read the one line out of the file.
 * Your main should pass the string to a function that checks to see if this
 * has the correct punctuation for a C++ for loop. The function should return
 * a Boolean value to indicate the outcome. The main should display a message
 * for the user.
 *
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

#include "LinkedStack.h"
#include "Node.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

#define DEBUG 0
using namespace std;

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Your main should ask the user for the name of the input file. Your main will
 * open the file and if it opened correctly, read the one line out of the file.
 * Your main should pass the string to a function that checks to see if this
 * has the correct punctuation for a C++ for loop. The function should return
 * a Boolean value to indicate the outcome. The main should display a message
 * for the user.
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

void debugPrint(string);
bool checkForLoopPunctuation(string);

int main()
{

    string filename;
    ifstream inputFile;
    string oneLine;

    // ask the user for the name of the input file
    cout << "Please enter the name of the input file: ";
    getline(cin >> ws, filename);
    // debugPrint filename
    debugPrint("debugPrint main filename: " + filename);

    // open the file
    inputFile.open(filename);
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    // read the one line out of the file
    getline(inputFile, oneLine);
    // debugPrint oneLine
    debugPrint("debugPrint main oneLine: " + oneLine);

    // remove all whitespace from the string
    oneLine.erase(remove_if(oneLine.begin(), oneLine.end(), ::isspace),
                  oneLine.end());
    // debugPrint oneLine after removing whitespace
    debugPrint("debugPrint main oneLine after removing whitespace: " + oneLine);

    // pass the string to a function that checks to see if this has the correct
    // punctuation for a C++ for loop

    bool isValid = checkForLoopPunctuation(oneLine);
    debugPrint("debugPrint main isValid: " + to_string(isValid));

    if (isValid) {
        cout << "The first line of the file " + filename +
                    " has correct for-loop punctuation."
             << endl;
    }
    else {
        cout << "The first line of the file " + filename +
                    " has incorrect for-loop punctuation."
             << endl;
    }

    // close the file
    inputFile.close();

    return 0;
}

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * bool checkForLoopPunctuation(string oneLine)
 * - input: string oneLine - the line of code to check for correct punctuation
 * - output: bool - true if the punctuation is correct, false otherwise
 *
 ********1*********2*********3*********4*********5*********6*********7*********8
 *
 *
 * You will write a program to determine if the punctuation in a C++ for-loop
 * is correct using a stack. You will be checking for correct punctuation only;
 * you just skip over the rest of the characters. You will be checking for the
 * following:
 *
 *  - Loop heading with the three parts with semi-colons and in parentheses:
 *    for (initialization; test; update) with no semi-colon at the end
 *  - Loop body having open and close curly braces if there is more than one
 *    statement in the block
 *  - Semi-colon at the end of each line in the block
 *
 ********1*********2*********3*********4*********5*********6*********7*********8

 * You will use the Link-based implmenetation of the ADT Stack provided with
 * the assignment. This ADT was covered in Chapter 7. The files are attached to
 * this assignment. There is no reason to modify any of these five files.
 *  - StackInterface.h,
 *  - Node.h,
 *  - Node.cpp,
 *  - LinkedStack.h,
 *  - LinkedStack.cpp
 *
 * You do not need to have the 'peek' method throw an exception if the stack is
 * empty - you can leae that code as-is in the 'LinkedStack' files.
 *
 * You will get the input to test from a text file. The file will contain the
 * for loop code to check as one continuous string - not on separate lines as
 * you would find it in a C++ source code file.
 *
 * Strategy:
 * 1. Check for the "for" keyword and ensure it is followed by an opening
 *   parenthesis '('.
 * 2. Use a stack to track the opening and closing of parentheses '()' and
 *  curly braces '{}'.
 * 3. Ensure that the loop header has exactly two semicolons ';' and no
 *  semicolon at the end of the header.
 * 4. After the loop header, check for the loop body. If there are multiple
 * statements, ensure that the body is enclosed in curly braces '{}'.
 * 5. Ensure that each statement in the loop body ends with a semicolon ';'.
 * 6. Return true if all checks pass, otherwise return false.
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

bool checkForLoopPunctuation(string oneLine)
{

    LinkedStack<char> stackPunctuation;
    // debugPrint oneLine
    debugPrint("debugPrint checkForLoopPunctuation oneLine: " + oneLine);

    // check for the "for" keyword and ensure it is followed by an opening
    // parenthesis '('.
    size_t forPosition = oneLine.find("for");
    if (forPosition == string::npos) {
        debugPrint("debugPrint checkForLoopPunctuation: 'for' not found");
        return false;
    }
    debugPrint("debugPrint checkForLoopPunctuation: 'for' found at position " +
               to_string(forPosition));
    size_t openParenPosition = oneLine.find('(', forPosition);
    if (openParenPosition == string::npos) {
        debugPrint(
            "debugPrint checkForLoopPunctuation: '(' not found after 'for'");
        return false;
    }
    debugPrint("debugPrint checkForLoopPunctuation: '(' found at position " +
               to_string(openParenPosition));
    stackPunctuation.push('(');

    // check for the closing parenthesis ')'
    size_t closeParenPosition = oneLine.find(')', openParenPosition);
    if (closeParenPosition == string::npos) {
        debugPrint(
            "debugPrint checkForLoopPunctuation: ')' not found after '('");
        return false;
    }
    debugPrint("debugPrint checkForLoopPunctuation: ')' found at position " +
               to_string(closeParenPosition));
    stackPunctuation.push(')');

    // check for two semicolons ';' in the loop header and no semicolon at
    // the end of the header

    string loopHeader = oneLine.substr(
        openParenPosition + 1, closeParenPosition - openParenPosition - 1);
    debugPrint("debugPrint checkForLoopPunctuation: loopHeader: " + loopHeader);
    size_t semicolonCount =
        std::count(loopHeader.begin(), loopHeader.end(), ';');
    debugPrint("debugPrint checkForLoopPunctuation: semicolonCount: " +
               to_string(semicolonCount));
    if (semicolonCount != 2) {
        debugPrint(
            "debugPrint checkForLoopPunctuation: loopHeader does not have 2 "
            "semicolons");
        return false;
    }

    // check for the loop body whether it has multiple statements and if so,
    // ensure that the body is enclosed in curly braces '{}'.
    size_t bodyStartPosition = closeParenPosition + 1;
    if (bodyStartPosition >= oneLine.size()) {
        debugPrint(
            "debugPrint checkForLoopPunctuation: loop body not found after "
            "loop header");
        return false;
    }
    char bodyStartChar = oneLine[bodyStartPosition];
    debugPrint("debugPrint checkForLoopPunctuation: bodyStartChar: " +
               string(1, bodyStartChar));
    if (bodyStartChar == '{') {
        stackPunctuation.push('{');
        size_t bodyEndPosition = oneLine.find('}', bodyStartPosition);
        if (bodyEndPosition == string::npos) {
            debugPrint(
                "debugPrint checkForLoopPunctuation: '}' not found after '{'");
            return false;
        }
        debugPrint(
            "debugPrint checkForLoopPunctuation: '}' found at position " +
            to_string(bodyEndPosition));
        stackPunctuation.push('}');
        // check for semicolons in the loop body
        string loopBody = oneLine.substr(
            bodyStartPosition + 1, bodyEndPosition - bodyStartPosition - 1);
        debugPrint("debugPrint checkForLoopPunctuation: loopBody: " + loopBody);
        size_t semicolonCountInBody =
            std::count(loopBody.begin(), loopBody.end(), ';');
        debugPrint(
            "debugPrint checkForLoopPunctuation: semicolonCountInBody: " +
            to_string(semicolonCountInBody));
        if (semicolonCountInBody == 0) {
            debugPrint("debugPrint checkForLoopPunctuation: loopBody does not "
                       "have any "
                       "semicolons");
            return false;
        }
    }
    else {
        // if the loop body does not have {}, then there should be only one
        // statement
        size_t bodySemicolonCount =
            std::count(oneLine.begin() + bodyStartPosition, oneLine.end(), ';');
        debugPrint("debugPrint checkForLoopPunctuation: bodySemicolonCount: " +
                   to_string(bodySemicolonCount));
        if (bodySemicolonCount != 1) {
            debugPrint("debugPrint checkForLoopPunctuation: loop body does not "
                       "have exactly "
                       "one semicolon");
            return false;
        }
    }

    // check if the parentheses and curly braces are balanced
    if (!stackPunctuation.isEmpty()) {
        debugPrint("debugPrint checkForLoopPunctuation: stackPunctuation is "
                   "not empty");
        // check if the top of the stack is closing brace
        char topChar = stackPunctuation.peek();
        if (topChar == '}') {
            stackPunctuation.pop();
            if (stackPunctuation.isEmpty() || stackPunctuation.peek() != '{') {
                debugPrint(
                    "debugPrint checkForLoopPunctuation: stackPunctuation is "
                    "not balanced");
                return false;
            }
            stackPunctuation.pop();
        }
        else if (topChar == ')') {
            stackPunctuation.pop();
            if (stackPunctuation.isEmpty() || stackPunctuation.peek() != '(') {
                debugPrint(
                    "debugPrint checkForLoopPunctuation: stackPunctuation is "
                    "not balanced");
                return false;
            }
            stackPunctuation.pop();
        }
        else {
            debugPrint(
                "debugPrint checkForLoopPunctuation: stackPunctuation is not "
                "balanced");
            return false;
        }
    }
    // if we reach here, then the punctuation is correct
    // empty out the stack and return true
    while (!stackPunctuation.isEmpty()) {
        stackPunctuation.pop();
    }
    return true;
}

void debugPrint(string message)
{
    if (DEBUG) {
        cout << message << endl;
    }
}
