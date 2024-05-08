import requests

Valsts = "latvia"
url = "http://universities.hipolabs.com/search"
parametri = {"country" : Valsts}

atbilde = requests.get(url, params = parametri)
#print(atbilde.text)

saraksts = atbilde.json()

Universitates = []

for elems in saraksts:
    Universitates.append(elems["name"])

Universitates.sort()
for elems in Universitates:
    print(elems)