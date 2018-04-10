import argparse
import os
import sys

 
def createParser ():
    parser = argparse.ArgumentParser()
    parser.add_argument('test')
    parser.add_argument('program')
 
    return parser

def remove_last_line_break(line):
    if line[-1] == '\n':
        return line[:-1]
    return line

def read_test(test):
    s = test.readline()
    if s == "":
        return None
    question = ""
    answer = ""
    while s != "" and s != "-\n" and s != "\n":
        question += s
        s = test.readline()
    s = test.readline()
    while s != "" and s != "\n":
        answer += s
        s = test.readline()
    return remove_last_line_break(question), remove_last_line_break(answer)

if __name__ == '__main__':
    parser = createParser()
    args = parser.parse_args()
 
    with open(args.test, 'r') as test_file:
        test = read_test(test_file)
        i = 0
        correct = 0
        while test != None:
            question, answer = test
            with open("tmp_test", "w") as tmp_test:
                tmp_test.write(question)
                
            command = "./{} < {} > {}".format(args.program, "tmp_test", "tmp_out")
            os.system(command)
            with open("tmp_out", "r") as tmp_out:
                program_answer = tmp_out.read()
            if program_answer != answer:
                print("_______________\nError: test #{}".format(i))
                print(question)
                print("Correct answer: %s" % answer)
                print("Answer: %s" % program_answer)
            else:
                correct += 1
            i += 1
            test = read_test(test_file)
    print("Total: correct {}/{}".format(correct, i))