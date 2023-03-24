#Construa algoritmo que conte o número de vezes que uma palavra aparece em um arquivo

a = []
b = []


with open('texto.txt', 'r', encoding='utf-8') as arquivo:
    l = arquivo.readlines()
    for linha in l:
        linha = linha.strip('\n').split(' ')
        a.append(linha)


for texto in a:
    for palavra in texto:
        linha = []
        linha.append(palavra.lower())
        b.append(linha)


for i, j in enumerate(b):
   b[i] = j[0].replace(',','').replace('!','').replace('.','').replace('?', '').replace('(', '').replace(')', '').replace(':', '').replace(';', '')


contador = 0
word = str(input("Digite uma palavra: ")).lower()
for palavra in b:
    if word == palavra:
        contador += 1

print('O numero de vezes que a palavra {} apareceu foi {}.'.format(word, contador))