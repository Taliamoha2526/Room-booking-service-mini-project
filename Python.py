import pandas as pd

Room_details= pd.DataFrame(data=[['1', 'Single Room', 'RM 50', '1'],\
                                 ['2', 'Double Room', 'RM 90', '2'],\
                                 ['3', 'Deluxe Room', 'RM 150', '4'],\
                                 ['4', 'Suite', 'RM 250', '6']],\
                           columns=['Room_ID','Room Type','Price(RM)','Maximum Occupants'])
print(Room_details)

def Calcfee(id, num, customers):
    index = int(id) - 1
    if index < 0 or index > 3:
        raise ValueError('Unavailable room id, please try again.')
    if int(customers)<= int(Room_details['Maximum Occupants'][index])*int(num):
        Fee= int(Room_details['Price(RM)'][index].strip('RM')) * int(num)
        return Fee
    else:
        raise ValueError('Too many customers. Please try upgrading the room type')
def Get_dicount(Fee):
    if Fee>= 180:
        Final_fee= Fee*0.95
        return Final_fee
    else:
        Final_fee= Fee
        return Final_fee
input_id= input("Enter Room ID: ")
input_num= input("Enter Number of Rooms: ")
input_customers= input("Enter Number of Customers: ")
Fee_before_discount=int(Calcfee(input_id, input_num, input_customers))
Final_fee= Get_dicount(Fee_before_discount)
print('Initial fee: ' + str(Fee_before_discount))
print('Fee after discount: ' + str(Final_fee))