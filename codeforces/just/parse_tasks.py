#!/usr/bin/python3

import re
import requests
import sys
import os
from bs4 import BeautifulSoup
from shutil import copyfile

if len(sys.argv) < 2:
	print("Need contest number")
	sys.exit(0)

number = sys.argv[1]

r = requests.get("http://codeforces.com/contest/" + number + "/problems")
s = r.text
soup = BeautifulSoup(s)
probs = soup.findAll("div", {"class": "problemindexholder"})
for prob in probs:
	index = prob["problemindex"]
	if not os.path.exists(index):
		os.makedirs(index)
	samples = prob.find("div", {"class": "sample-test"})
	io = list(zip(samples.findAll("div", {"class": "input"}),
			 samples.findAll("div", {"class": "output"})))
	for i in range(len(io)):
		inp, out = io[i]
		with open("%s/in%d.in" % (index, i), "w") as f:
			f.writelines(inp.find("pre").text.strip())
		with open("%s/out%d.out" % (index, i), "w") as f:
			f.writelines(out.find("pre").text.strip())
	for file in ["qwe.cpp", "check.sh", "run.sh", "_input.txt", "_output.txt", "go.sh"]:
		copyfile(file, index + "/" + file)
