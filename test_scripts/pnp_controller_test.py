import serial
import time

# Define the COM port and baud rate
com_port = 'COM7'
baud_rate = 115200
uart_handshake = False
mcu_ready_for_command = False

PC_HANDSHAKE = "PCH".encode('utf-8')

message_list = ["M03\n".encode('utf-8'), "M04\n".encode('utf-8'), "M10\n".encode('utf-8')]



def send_uart_message(ser, message):
    ser.write(message)
    print(f"Sent: {message}")

try:
    # Open the serial port
    ser = serial.Serial(com_port, baud_rate, timeout=1)

    send_uart_message(ser, PC_HANDSHAKE)

    while(not uart_handshake):

        received_data = ser.readline()  # Read a line of data (until '\n' or timeout)
        
        if received_data:
            try:
                # Attempt to decode as UTF-8, falling back to Latin-1 if it fails
                decoded_data = received_data.decode('utf-8')
            except UnicodeDecodeError:
                decoded_data = received_data.decode('latin-1', errors='replace')

            # Echo the received data
            print(decoded_data.strip())

            if(decoded_data == "MCUH\n"):
                uart_handshake = True
        else:
            
            time.sleep(0.1)


    for message in message_list:

        while(not mcu_ready_for_command):

            received_data = ser.readline()  # Read a line of data (until '\n' or timeout)
            
            if received_data:
                try:
                    # Attempt to decode as UTF-8, falling back to Latin-1 if it fails
                    decoded_data = received_data.decode('utf-8')
                except UnicodeDecodeError:
                    decoded_data = received_data.decode('latin-1', errors='replace')

                # Echo the received data
                print(decoded_data.strip())

                if(decoded_data == "MCUR\n"):
                    mcu_ready_for_command = True
        send_uart_message(ser, message)
        mcu_ready_for_command = False
        







    ser.close()

except KeyboardInterrupt:
    # Handle Ctrl+C to gracefully exit the script
    print("Script terminated by user.")
except serial.SerialException as e:
    # Handle serial port errors
    print(f"Serial port error: {e}")



    
    





# continually send pc handshake until mcu handshake received_data
# when mcu handshake received, alternate between sending commands and waiting for ready


# some notes:
# all t code commands must be formatted exactly as in the spreadsheet, including spaces, but must also end with newlines
