def greet(name, year):
    print("Hello! My name is " + name + ". Nice to meet you.")
    print("I was created in " + year + ".")

def ask_name():
    print("What is your name?")
    name = input()
    print("Nice name, " + name + ".")

def guess_age():
    print("Let me guess your age.")
    print("Give me the remainders of your age divided by 3, 5, and 7.")
    num3 = int(input("Enter the remainder by 3: "))
    num5 = int(input("Enter the remainder by 5: "))
    num7 = int(input("Enter the remainder by 7: "))

    age = (num3 * 70 + num5 * 21 + num7 * 15) % 105

    print("Your age is {0}; it is a good time to learn some programming.".format(age))

def count():
    print("I want you to try me. Just throw me a number and I can count till that number.")
    numb = int(input())

    if numb >= 1000:
        print("I can't count that much, but it will take some time. Please enter a lower value.")
        numb = int(input())

    if numb > 800:
        print("Just go below 500.")
        numb = int(input())

    if numb < 500:
        i = 0
        while i < numb:
            print(i)
            i += 1
    else:
        print("Okay, you're not listening. Here you go.")
        i = 0
        while i < 500:
            print(i)
            i += 1

def test():
    print("Let me ask you one programming question.")
    print("Which of the following is NOT a programming language?")
    print("1. Python")
    print("2. HTML")
    print("3. Java")
    print("4. Photoshop")

    guess = int(input("Enter your choice: "))
    answer = 4
    while answer != guess:
        print("Wrong answer. Let's try again.")
        guess = int(input())

    print("Congratulations! That's the right answer.")

def bye():
    print("It was nice talking to you. Bye!")

greet('rbot', "2023")
ask_name()
guess_age()
count()
test()
bye()
