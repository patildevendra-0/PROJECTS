
import os
import psutil
import time
from sys import *

def DisplayProcess(log_dir):

    listprocess = []

    if not os.path.exists(log_dir):
        try:
            os.mkdir(log_dir)
        except:
            pass

    separator = " "*80
    log_path = os.path.join(log_dir,"ProcessLog%s.log"%(time.time()))
    f = open(log_path,'w')
    f.write(separator+"\n")
    f.write("process logger: "+time.ctime()+"\n")
    f.write(separator+"\n")

    for proc in psutil.process_iter():
        try:
            pinfo = proc.as_dict(attrs=['pid','status','name','username'])
            vms = proc.memory_info().vms/(1024*1024) 
            pinfo['vms']=vms 
            listprocess.append(pinfo)
        except(psutil.NoSuchProcess,psutil.ZombieProcess,psutil.AccessDenied):
            pass

        for element in listprocess:
            f.write("%s\n"%element)                

def main():

    print("_________________________________________________________________________________")
    print("-------------------------WELCOME TO PROCESS LOG SCRIPT---------------------------")
    print("_________________________________________________________________________________")
    print("Appliaction Name : "+argv[0])

    if(len(argv)!=2):
        print("Invalide number of arguments")
        exit()

    if(argv[1]=="-u")or(argv[1]=="-U"):
        print("USAGE: Application_name Absolute_path")  

    if(argv[1]=="-h")or(argv[1]=="-H"):
        print("HELP : This script is used to process monitor with lof facilities")
        exit()

    
    DisplayProcess(argv[1])



if __name__=="__main__":
    main()    