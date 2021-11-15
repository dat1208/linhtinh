import requests
from bs4 import BeautifulSoup

def get_name():
    name = input("Nhập tên diễn viên:")
    return name

def idols(list):
    j = 0
    for i in list:
        j += 1
        print(str(j)+" - "+i)

def pick_idol(list, id):
    return list[id-1]

reponse_idol = requests.get("https://xxx.xcity.jp/idol/?genre=%2Fidol%2F&q="+get_name()+"&sg=idol&num=30&page=1")
reponse_idol = BeautifulSoup(reponse_idol.content,"html.parser")
reponse_idol = reponse_idol.find_all(id="avidol")[0]
reponse_idol = reponse_idol.find_all(class_="name")
reponse_idol_str = str(reponse_idol).split("\"")
reponse_idol_list = list(reponse_idol_str)
i = 5
list_idol = []
while i <= len(reponse_idol_list):
    if i not in list_idol:
        temp = reponse_idol_list[i]
        list_idol.append(temp)
    i = i + 5 + 1
idols(list_idol)
id = int(input("Nhập STT idol muốn chọn:"))
print(pick_idol(list_idol,id))


#tìm code idol
response = requests.get("https://javfilm.tv/?s="+str(pick_idol(list_idol,id)))
response_beuty = BeautifulSoup(response.content,"html.parser")
response_beuty_wrap = response_beuty.find(class_="loop-content switchable-view grid-small")
response_beuty_text = response_beuty_wrap.text
text = response_beuty_text.split()
Jav_id = []
for i in text:
    if "-" in i:
        Jav_id.append(i)
Jav_id = set(Jav_id)
Jav_id = list(Jav_id)
Jav_id_sort = []
for i in Jav_id:
    if len(i) > 3 and i.isupper():
        Jav_id_sort.append(i)

print("Danh sách code của diễn viên :).")
id = 0
for i in Jav_id_sort:
    id += 1
    print(str(id) + " - " + i)
