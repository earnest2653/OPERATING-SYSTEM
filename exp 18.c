import threading

import time

BUFFER_SIZE = 3

buffer = []

lock = threading.Lock()

not_full = threading.Condition(lock)

not_empty = threading.Condition(lock)

class Producer(threading.Thread):

    def run(self):

        global buffer

        items = [1, 2, 3, 4]

        for item in items:

            with not_full:

                while len(buffer) == BUFFER_SIZE:

                    print("Buffer is full, waiting for consumer...")

                    not_full.wait()

                buffer.append(item)

                print(f"Produced item {item}")

                time.sleep(1)  # Simulating some processing time

                with not_empty:

                    not_empty.notify()  # Notify the consumer

class Consumer(threading.Thread):

    def run(self):

        global buffer

        while True:

            with not_empty:

                while len(buffer) == 0:

                    print("Buffer is empty, waiting for producer...")

                    not_empty.wait()

                item = buffer.pop(0)

                print(f"Consumed item {item}")

                time.sleep(1)  # Simulating some processing time

                with not_full:

                    not_full.notify()  # Notify the producer

# Create and start the producer and consumer threads

producer = Producer()

consumer = Consumer()

consumer.start()

time.sleep(1)  # Ensure consumer starts first

producer.start()

# Wait for the producer and consumer to finish

producer.join()

consumer.join()
