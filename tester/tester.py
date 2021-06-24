# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 17:05:45 by abaudot           #+#    #+#              #
#    Updated: 2021/06/24 19:22:10 by abaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import subprocess
from random import shuffle
from itertools import permutations
import sys
exec(open("config.py").read())     


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    PURPLE = '\033[0;35m'
    YELOW = '\033[0;33m'

    TEST = '\033[103m'
    
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

    ENDC = '\033[0m'

def all_perm(size):
    max = 0;
    perm = list(permutations(['%d' %i for i in range(1, size + 1)]))
    for p in perm:
        ps = subprocess.run([path + "./push_swap", *p], stdout=subprocess.PIPE)
        num = len(ps.stdout.split())
        if num > max:
            max = num
        check = subprocess.run([path_checker + "./checker", *p], input=ps.stdout, stdout=subprocess.PIPE)
        if 'OK' in str(check.stdout):
            continue
        print(bcolors.WARNING + "ERROR" + bcolors.ENDC, p)
        return (0)
    return (max)

def sample_shuffle(size, n):
    max = 0;
    l = ["%d" %i for i in range(size)];
    for i in range(n):
        shuffle(l);
        ps = subprocess.run([path + "./push_swap", *l], stdout=subprocess.PIPE)
        num = len(ps.stdout.split())
        if num > max:
            max = num   
        check = subprocess.run([path_checker + "./checker", *l], input=ps.stdout, stdout=subprocess.PIPE)
        if 'OK' in str(check.stdout):
            continue
        print(bcolors.WARNING + "ERROR" + bcolors.ENDC, l)
        return (0)
    return (max)




subprocess.run(["clear"], shell=True)
subprocess.run(["echo ''"], shell=True)
subprocess.run(["echo ''"], shell=True)
subprocess.run(["echo ''"], shell=True)
subprocess.run(["echo ''"], shell=True)

subprocess.run(["cat header"], shell=True)
subprocess.run(["echo ''"], shell=True)
subprocess.run(["echo ''"], shell=True)
subprocess.run(["echo ''"], shell=True)

print(bcolors.HEADER + "0)\tcompiling:" + bcolors.ENDC)
subprocess.run(["make -C" + path], shell=True)

print(bcolors.HEADER + "\n1)\ttesting all solutions relative to 3 elements:" + bcolors.ENDC)
tt = all_perm(3)
if tt > 2 or tt == 0:
    print (bcolors.FAIL + "your mark: 0" + bcolors.ENDC)
    exit()
else:
    print (bcolors.OKGREEN + "OK!\tmax: ", tt, bcolors.ENDC)

print(bcolors.HEADER + "\n2)\ttesting all solutions relative to 5 elements:" + bcolors.ENDC)
tt = all_perm(5)
if tt > 12 or tt == 0:
    print (bcolors.FAIL + "your mark: 0" + bcolors.ENDC)
    exit()
else:
    print (bcolors.OKGREEN + "OK!\tmax: ", tt, bcolors.ENDC)

print(bcolors.HEADER + "\n3)\ttesting a " + str(nb_of_test) + " random samble for 100 elements:" + bcolors.ENDC)
tt = sample_shuffle(100, nb_of_test)
if (tt == 0 or tt >= 1500):
    print (bcolors.FAIL + "your mark: 0" + bcolors.ENDC)
elif (tt < 700):
    print (bcolors.OKGREEN + "OK!\t max: ", tt, "\tscore: 5/5" + bcolors.ENDC)
elif (tt < 900):
    print (bcolors.OKCYAN + "OK!\t max: ", tt, "\tscore: 4/5" + bcolors.ENDC)
elif (tt < 1100):
    print (bcolors.OKCYAN + "OK!\t max: ", tt, "\tscore: 3/5" + bcolors.ENDC)
elif (tt < 1300):
    print (bcolors.OKBLUE + "OK!\t max: ", tt, "\tscore: 2/5" + bcolors.ENDC)
elif (tt < 1300):
    print (bcolors.WARNING + "OK!\t max: ", tt, "\tscore: 1/5" + bcolors.ENDC)

print(bcolors.HEADER + "\n4)\ttesting a " + str(nb_of_test) + " random samble for 500 elements:" + bcolors.ENDC)
tt = sample_shuffle(500, nb_of_test)
if (tt == 0 or tt >= 11500):
    print (bcolors.FAIL + "your mark: 0" + bcolors.ENDC)
elif (tt < 5500):
    print (bcolors.OKGREEN + "OK!\t max: ", tt, "\tscore: 5/5" + bcolors.ENDC)
elif (tt < 7000):
    print (bcolors.OKCYAN + "OK!\t max: ", tt, "\tscore: 4/5" + bcolors.ENDC)
elif (tt < 8500):
    print (bcolors.OKCYAN + "OK!\t max: ", tt, "\tscore: 3/5" + bcolors.ENDC)
elif (tt < 10000):
    print (bcolors.OKBLUE + "OK!\t max: ", tt, "\tscore: 2/5" + bcolors.ENDC)
elif (tt < 11500):
    print (bcolors.WARNING + "OK!\t max: ", tt, "\tscore: 1/5" + bcolors.ENDC)

print(bcolors.HEADER + "\n4)\t Final testing 2 random sambles for [2 -> " + str(upper_limit) + "] elements:" + bcolors.ENDC)
#load1 = upper_limit / 10
#load2 = upper_limit / 3
#load3 = upper_limit / 2
#load4 = upper_limit - load2
for i in range(2, 1501) :
    tt = sample_shuffle(i, 2)
    if tt == 0 :
        print (bcolors.FAIL + "fail " + str(i) + "test:\tyour mark: 0" + bcolors.ENDC)
        quit()
 #   if i == load1:
 #       subprocess.run(["echo -ne"], input =  bcolors.PURPLE + "\t|###" + bcolors.YELOW + "...................." + bcolors.ENDC, shell=True)
 #   elif i == load2:
 #       subprocess.run(["echo", "-ne", bcolors.PURPLE + "\t|######" + bcolors.YELOW + "................." + bcolors.ENDC], shell=True)
 #   elif i == load3:
 #      subprocess.run(["echo", "-ne", bcolors.PURPLE + "\t|#########" + bcolors.YELOW + "..............." + bcolors.ENDC], shell=True)
 #   elif i == load4:
 #      subprocess.run(["echo", "-ne", bcolors.PURPLE + "\t|############" + bcolors.YELOW + "............" + bcolors.ENDC], shell=True)


print (bcolors.OKGREEN + "OK!\t all tests passed !" + bcolors.ENDC)
