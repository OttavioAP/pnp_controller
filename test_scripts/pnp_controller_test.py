import serial

# Define the COM port and baud rate
com_port = 'COM7'
baud_rate = 115200
uart_handshake = False

PC_HANDSHAKE = "PCH".encode('utf-8')


def send_uart_message(ser, message):
    ser.write(message)
    print(f"Sent: {message}")

try:
    # Open the serial port
    ser = serial.Serial(com_port, baud_rate, timeout=1)

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
            send_uart_message(ser, PC_HANDSHAKE)



    ser.close()

except KeyboardInterrupt:
    # Handle Ctrl+C to gracefully exit the script
    print("Script terminated by user.")
except serial.SerialException as e:
    # Handle serial port errors
    print(f"Serial port error: {e}")



    
    





# continually send pc handshake until mcu handshake received_data
# when mcu handshake received, alternate between sending commands and waiting for ready
