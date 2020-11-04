import json
import random

with open('data.json') as f:
    data = json.load(f)

counter = 0
for i in data['quote']: 
    if i: 
        counter += 1
          

while True:
    quoteno= random.randint(0,counter-1)
    quote = data['quote'][quoteno]
    for y in quote:
        authorname = y
    print(quote[y],'\n -by',y)
    
    Continue = input('''\nPress '1' for more quotes \nPress '2'  to stop\n ''')
    if Continue == '1':
        continue
    elif Continue == '2':
        break
    
