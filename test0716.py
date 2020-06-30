
import serial
from time import sleep
import sys
 
COM_PORT = '/dev/ttyACM0'  # 請自行修改序列埠名稱
BAUD_RATES = 1000000
ser = serial.Serial(COM_PORT, BAUD_RATES)


while True:

    # 接收用戶的輸入值並轉成小寫
    choice = input('按y開始  ').lower()

    if choice == 'y':
        print('傳送開始指令')
        ser.write(b'move\n')  # 訊息必須是位元組類型
        sleep(1.1)              
        ser.write(b'kkk\n')
    elif choice == 'n':
        print('傳送束指令')
        ser.write(b'kkk\n')  # 訊息必須是位元組類型
        sleep(0.5) 

    else:
        print('指令錯誤…')

   