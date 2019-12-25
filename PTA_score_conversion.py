#import os
file = open("score.txt", "w")
b = e = 1.0;
while(True):
    score = int(input())
#for score in range(0, 101):
#    print("{0} ".format(score))
    if score<0:
        break
    if score<15:
        e = 34/14.0;
        b = e
        ratio = (score-0.0)/14
    elif score<35:
        b = 35/15.0
        e = 50/34.0
        ratio = (score-15.0)/(34-15)
    elif score<50:
        b = 60/35.0
        e = 79/49.0
        ratio = (score-35.0)/(49-35)
    elif score<75:
        b = 80/50.0
        e = 89/74.0
        ratio = (score-50.0)/(74-50)
    elif score<90:
        b = 90/75.0
        e = 99/89.0
        ratio = (score-75.0)/(89-75)
    else:
        b = e = 100;
        ratio = 1.0
    ratio = b*(1-ratio)+e*ratio;
    score =int(score*ratio);
    if score<=5:
        score = 5
    elif score>=100:
        score = 100
    file.write("{0}\n".format(score));
    print("{0}\n".format(score))
file.close();
