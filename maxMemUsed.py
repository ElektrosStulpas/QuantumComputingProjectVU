import argparse
import psutil

parser = argparse.ArgumentParser()

parser.add_argument("-p", "--procName", type=str,
                    help="Provide a process name to measure memory for.")
args = parser.parse_args()

procName = args.procName


runningProc = ""
mostMemoryUsed = 0

while runningProc == "":
    for proc in psutil.process_iter():
            if proc.name() == procName:
                runningProc = proc

while 1:
    try:
        currentMemoryUse = runningProc.memory_info()[0]/2.**30  # memory use in GB...I think
        if currentMemoryUse > mostMemoryUsed:
            mostMemoryUsed = currentMemoryUse
    except psutil.NoSuchProcess:
        print('Most memory used:', mostMemoryUsed)
        exit()