# This program was tailor made with the support of Mr. Mohan Paineti (GITAM student)

import xlwt  # used to generate spreadsheets
import xlrd  # used for reading data from excel files
from xlutils.copy import copy   # tools for copying xlwt workbook
workbook = xlwt.Workbook()
worksheet = workbook.add_sheet("marks")
##rb = xlrd.open_workbook("marks.xls")
##wb = copy(rb)
##w_sheet = wb.get_sheet("marks")
##w_sheet.write(c,0,"PIN")
##w_sheet.write(c,1,"NAME")
##w_sheet.write(c,2,"Discrete_Mathematics_19EMA107")
##w_sheet.write(c,3,"Statistics_Probability_Calculus_19EMA109")
##w_sheet.write(c,4,"Fundamentals_of_Computer_Science_19ECB131")
##w_sheet.write(c,5,"Principles_of_Electrical_Engineering_19EEE133")
##w_sheet.write(c,6,"Physics_for_Computing_Science_19EPH137")
##w_sheet.write(c,7,"Business_Communications_and_Value_Science_I_19EMC183")
##w_sheet.write(c,8,"gpa")

workbook.save("marks.xls")
from selenium import webdriver # selenium is an open source tool that automates web browsers

from selenium.webdriver.common.keys import Keys 
import time
from selenium.webdriver.support.ui import Select
file_obj = open("registration_numbers.txt","r+")   # Input file that contains the list of registration numbers
#print(file_obj)

PATH="C:\Suraj\web-scrapping\chromedriver.exe"   # Google Chrome Driver path in the system
#print(PATH)

driver=webdriver.Chrome(PATH)
#print(driver)

driver.get("https://doeresults.gitam.edu/onlineresults/pages/newgrdcrdinput1.aspx")  # GITAM results portal

select = Select(driver.find_element_by_id('cbosem')) # Semester selection
select.select_by_value('1')  # selection of semester
time.sleep(1)
file_obj = open("registration_numbers.txt","r+")  # read data from the file containing registration numbers
reg = file_obj.readlines()
c = 1
for i in  reg:
    b = i.replace("\n","")
    reg_no = driver.find_element_by_id("txtreg")  # registration number in the form
    #reg_no.send_keys(Keys.CONTROL + 'a')
    #reg_no.send_keys(Keys.BACKSPACE)
    reg_no.clear()
    reg_no.send_keys(b)
    result = driver.find_element_by_id('Button1')  # Get Result button on the form
    result.click()
    registration_number = driver.find_element_by_id("lblregdno")
    name = driver.find_element_by_id("lblname")
    report_card = driver.find_element_by_class_name("table-responsive")
    #print(type(report_card))
    
    report_card_text = report_card.text[38:357]
    #print(report_card_text)
    report_card_words = report_card_text.split("\n")
    print(report_card_words)
    report_card_words_merged = []
    for line in report_card_words:
        words = line.split(" ")
        #print(words)
        report_card_words_merged += words
    #print(report_card_words_merged)
    Discrete_Mathematics_19EMA107 = report_card_words_merged[4]
    #print(Discrete_Mathematics_19EMA107)

    Statistics_Probability_Calculus_19EMA109 = report_card_words_merged[11]
    #print(Statistics_Probability_Calculus_19EMA109)

    Fundamentals_of_Computer_Science_19ECB131 = report_card_words_merged[18]
    #print(Fundamentals_of_Computer_Science_19ECB131)

    Principles_of_Electrical_Engineering_19EEE133 = report_card_words_merged[25]
    #print(Principles_of_Electrical_Engineering_19EEE133)

    Physics_for_Computing_Science_19EPH137 = report_card_words_merged[32]
    #print(Physics_for_Computing_Science_19EPH137)

    Business_Communications_and_Value_Science_I_19EMC183 = report_card_words_merged[40]
    #print(Business_Communications_and_Value_Science_I_19EMC183)

    gpa = driver.find_element_by_id("lblgpa")
    #print(gpa.text)
    time.sleep(1)
    
    rb = xlrd.open_workbook("marks.xls")
    wb = copy(rb)
    w_sheet = wb.get_sheet("marks")
    w_sheet.write(c,0,b)
    w_sheet.write(c,1,name.text)
    w_sheet.write(c,2,Discrete_Mathematics_19EMA107)
    w_sheet.write(c,3,Statistics_Probability_Calculus_19EMA109)
    w_sheet.write(c,4,Fundamentals_of_Computer_Science_19ECB131)
    w_sheet.write(c,5,Principles_of_Electrical_Engineering_19EEE133)
    w_sheet.write(c,6,Physics_for_Computing_Science_19EPH137)
    w_sheet.write(c,7,Business_Communications_and_Value_Science_I_19EMC183)
    w_sheet.write(c,8,gpa.text)
    wb.save("marks.xls")
    c+=1
    driver.back()
