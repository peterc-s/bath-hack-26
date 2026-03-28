import serial
import time

PORT = "/dev/ttyUSB0"
BAUD_RATE = 300


def main():
    try:
        with serial.Serial(
            PORT,
            BAUD_RATE,
            timeout=2,
            parity=serial.PARITY_NONE,
            bytesize=serial.EIGHTBITS,
            xonxoff=False,
            rtscts=False,
            dsrdtr=False,
            stopbits=1,
        ) as ser:
            print("Waiting 2 seconds for connection...")
            ser.dtr = True
            time.sleep(2)

            print("Resetting buffers")
            ser.reset_input_buffer()
            ser.reset_output_buffer()

            print("Sending: ping")
            ser.write(b"ping\r\n")
            # raw_response = ser.readline().decode("utf-8", errors="ignore")
            # clean_response = raw_response.strip().replace("\x00", "")
            #
            # if "pong" in clean_response:
            #     print(f"Success! Received: {clean_response}")
            # else:
            #     print(f"Unexpected data: {repr(raw_response)}")

    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
