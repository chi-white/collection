Loan = int(input("loan(ten thousands):"))*10000
Loan_period = int(input("Loan_period(years) :"))*12
Grace_period = int(input("Grace_period(years) :"))*12
rate = 0.0133/12
print("本金攤還法")
report_1 = list()
principal_period = Loan_period - Grace_period
remain_loan = Loan
for i in range(1,Loan_period+1) :
    interest = remain_loan * rate
    if i <= Grace_period :#只還利息
        principal = 0
    else :
        principal = Loan/principal_period
    payment = interest + principal
    remain_loan = remain_loan - principal
    report_1.append([i, int(principal), int(interest), int(payment)])
print("{:<8} {:<8} {:<8} {:<8}".format('期數', '應付本金', '應付利息', '應付本息'))
for a in report_1 :
	date, principal, interest, payment = a
	print("{:<12} {:<12} {:<12} {:<12}".format(date, principal, interest, payment))

print("本息平均攤還法")
report_2 = list()
principal = 0
remain_loan = Loan 
c = Loan/(1/rate - 1/(rate*(1+rate)**principal_period))
for i in range(1, Loan_period+1) :
	remain_loan = remain_loan - principal
	interest = remain_loan * rate
	if i <= Grace_period :
		principal = 0
	else :
		principal = c - interest
	payment = principal + interest
	report_2.append([i, int(principal), int(interest), int(payment)])
print("{:<8} {:<8} {:<8} {:<8}".format('期數', '應付本金', '應付利息', '應付本息'))
for a in report_2 :
	date, principal, interest, payment = a
	print("{:<12} {:<12} {:<12} {:<12}".format(date, principal, interest, payment))