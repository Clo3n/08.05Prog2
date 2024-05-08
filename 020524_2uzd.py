import string

Fails = open("Teksts.txt", "r", encoding="utf-8")
txtdati = Fails.read()
Fails.close()

#print(txtdati)

Vardnica = {}
Atslegasvardi = txtdati.split()

#print(Atslegasvardi)

for vardi in Atslegasvardi:
  if vardi[-1] in string.punctuation:
    vardi = vardi.rstrip(string.punctuation)

  if len(vardi) >= 4:
    if vardi in Vardnica:
      Vardnica[vardi] += 1
    else:
      Vardnica[vardi] = 1

Vardnica_sorted = dict(sorted(Vardnica.items(), key=lambda x: x[1], reverse=True))

X = 0

for elems, count in Vardnica_sorted.items():
  print(f"{elems}: {count}")
  X+=1
  if X ==5: break
