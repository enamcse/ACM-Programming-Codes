#!/usr/bin/python

import os
import requests
import sys
import itertools
import time

# Edit these four variables according to your needs:
x_user = "8c7f64d63ff0f9a619fad54d6890b89005a15c35ebef2284d849e1b6fbe6b67d2664fc5929207aca"
csrf_token = "3cf53164b519e1d78491ef83ae406c83"
cf_domain = "com"  # "ru" if you prefer codeforces.ru
ext_id = {
    "cpp":   "16",
    "cs":    "29",
    "go":    "32",
    "java":  "36",
    "py":    "31",
}

# programTypeId - Language
# 1: GNU G++ 4.9.2
# 10: GNU GCC 4.9.2
# 12: Haskell GHC 7.6
# 13: Perl 5.12
# 14: ActiveTcl 8.5
# 15: Io-2008-01-07 (Win32)
# 16: GNU G++11 4.9.2
# 17: Pike 7.8
# 18: Befunge
# 19: OCaml 4
# 2: Microsoft Visual C++ 2010
# 20: Scala 2.11
# 22: OpenCobol 1.0
# 23: Java 7
# 25: Factor
# 26: Secret_171
# 27: Roco
# 28: D DMD32 Compiler v2
# 29: MS C# .NET 4
# 3: Delphi 7
# 31: Python 3.4
# 32: Go 1.2
# 33: Ada GNAT 4
# 34: JavaScript V8 3
# 36: Java 8
# 38: Mysterious Language
# 39: FALSE
# 4: Free Pascal 2
# 5: Java 6
# 6: PHP 5.3
# 7: Python 2.7
# 8: Ruby 2
# 9: C# Mono 2.1


def is_gym(contest_id):
    return int(contest_id) >= 100000

if len(sys.argv) < 2:
    print("Solution filename not specified")
    sys.exit()

if not os.path.exists(sys.argv[1]):
    print("Solution file does not exist or not enough rights to read it")
    sys.exit()

filename = os.path.basename(sys.argv[1])

contest_id = ''.join(itertools.takewhile(lambda c: c.isdigit(), filename))
problem_index = ''.join(itertools.takewhile(
    lambda c: c != '.', filename[len(contest_id):])).upper()
extension = filename[len(contest_id) + len(problem_index) + 1:].lower()

if (len(contest_id) == 0) or (len(problem_index) == 0):
    print("Incorrect filename format. Example: 123A.cpp")
    sys.exit()
if extension not in ext_id:
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

submit_addr = "http://codeforces.%s/%s/%s/submit" % (
    cf_domain, "gym" if is_gym(contest_id) else "contest", contest_id)

requests.post(submit_addr, params={"csrf_token": csrf_token},
              files=parts, cookies={"X-User": x_user})

print("Solution sent. Current time is " + time.strftime("%H:%M:%S"))
