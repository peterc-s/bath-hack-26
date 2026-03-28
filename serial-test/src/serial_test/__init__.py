import serial
import time

PORT = "/dev/ttyACM0"
BAUD_RATE = 9600


def main():
    try:
        with serial.Serial(PORT, BAUD_RATE, timeout=2) as ser:
            print("Waiting 2 seconds for connection...")
            time.sleep(2)

            print("Resetting buffers")
            ser.reset_input_buffer()
            ser.reset_output_buffer()

            print("Sending: ping")
            ser.write(b"ping\n")
            raw_response = ser.readline().decode("utf-8", errors="ignore")
            clean_response = raw_response.strip().replace("\x00", "")

            if "pong" in clean_response:
                print(f"Success! Received: {clean_response}")
            else:
                print(f"Unexpected data: {repr(raw_response)}")

    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
