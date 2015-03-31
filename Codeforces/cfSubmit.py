#!/usr/bin/python3
import os
import requests
import sys
import itertools
import time

# Edit these four variables according to your needs:
x_user          =  "581c4127b86299852b2d758be1491e1575c3e329419ec47a0956efd99656076cf746a16b3daaf888"
csrf_token      =  "5b2995949be201c38efda0f6849f8ff6"
cf_domain       =  "com" #"com" if you prefer codeforces.com
username        =  "manetsus"
updateInterval  =  2 #in seconds
countOfSubmits  =  5 #count of previous submits, shown after done submission. If count == 1, nothing happens.
ext_id          =  {
    "cpp":   "16",
    "hs":    "12",
    "java":  "36",
    "py":    "31",
}

# programTypeId - Language
# 10 - GNU C 4
# 1  - GNU C++ 4.7
# 16 - GNU C++0x 4
# 2  - Microsoft Visual C++ 2010
# 9  - C# Mono 2.10
# 29 - MS C# .NET 4
# 28 - D DMD32 Compiler v2
# 32 - Go 1.2
# 12 - Haskell GHC 7.6
# 5  - Java 6
# 23 - Java 7
# 36 - Java 8
# 19 - OCaml 4
# 3  - Delphi 7
# 4  - Free Pascal 2
# 13 - Perl 5.12
# 6  - PHP 5.3
# 7  - Python 2.7
# 31 - Python 3.3
# 8  - Ruby 2
# 20 - Scala 2.11
# 34 - JavaScript V8 3

if len(sys.argv) < 2:
    print("Solution filename not specified")
    sys.exit()

if not os.path.exists(sys.argv[1]):
    print("Solution file does not exist or not enough rights to read it")
    sys.exit()

filename = os.path.basename(sys.argv[1])

contest_id = ''.join(itertools.takewhile(lambda c: c.isdigit(), filename))
problem_index = ''.join(itertools.takewhile(lambda c: c != '.', filename[len(contest_id):])).upper()
extension = filename[len(contest_id) + len(problem_index) + 1:].lower()

if (len(contest_id) == 0) or (len(problem_index) == 0):
    contest_id = os.path.dirname(os.path.realpath(sys.argv[1])).split(os.sep)[-1]
    temp = filename.split('.')
    problem_index = temp[0].upper()
    extension = temp[-1].lower()
    if (not contest_id.isdigit() or (len(problem_index) > 2)):
        print("Incorrect filename format. Example: 123A.cpp or 123/A.cpp")
        sys.exit()

if not extension in ext_id:
    print("Unknown extension. Please check 'ext_id' variable")
    sys.exit()


parts = {
        "csrf_token":            csrf_token,
        "action":                "submitSolutionFormSubmitted",
        "submittedProblemIndex": problem_index,
        "source":                open(sys.argv[1], "rb"),
        "programTypeId":         ext_id[extension],
        "sourceFile":            "",
        "_tta":                  "222"
}

requests.post("http://codeforces." + cf_domain + "/contest/" + contest_id + "/problem/" + problem_index,
              params = {"csrf_token": csrf_token},
              files = parts,
              cookies = {"X-User": x_user})

print("Solution is successfully sent. Current time is " + time.strftime("%H:%M:%S"))

while True:
    try:
        data = requests.get("http://codeforces.ru/api/user.status?handle=" + username + "&from=1&count=" + str(countOfSubmits)).json()['result']
    except:
        sleep(updateInterval)
        continue
    if countOfSubmits > 1:
        print("last submits")
        for s in reversed(data[1:]):
            print(str(s['problem']['contestId']) + s['problem']['index'] + " " + \
                    '{:>20}'.format(s['verdict'] + "(" + str(s['passedTestCount'] + 1) + ") ") + str(s['timeConsumedMillis']) + " ms")
        sys.stdout.flush()
    s = data[0]
    print(str(s['problem']['contestId']) + s['problem']['index'] + " " + \
            '{:>20}'.format(s['verdict'] + "(" + str(s['passedTestCount'] + 1) + ") ") + str(s['timeConsumedMillis']) + " ms")
    if s['verdict'] != 'TESTING':
        break
    sleep(updateInterval)
