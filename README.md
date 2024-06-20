

## General Execution Steps

To compile and run each program, follow these general steps:

1. **Compile the program:**
   ```bash
   cc <fname.c>
2. **Execute the compiled program:**
   ```bash
   ./a.out <fname1> <fname2>  # Use filenames if required
   
## Setting Up the Cron Job

1. **Create the Script:**
   ```bash
   vi create_file.sh
   #check the content in files section
2. **Set Execute Permissions:**
   ```bash
   chmod +x create_file.sh
3. **Edit the Crontab(nano):**
   ```bash
   crontab -e
4. **Write the cron/schedule expression as per your requirement (for eg. Run the script on 4:32 PM everyday ) :**
   ```bash
   32 16 * * * cd /home/amogu/ && ./create_file.sh
   # Save and exit (Ctrl + O, then Enter, Ctrl + X in nano)
5. **Check date and list all files and directories:**
   ```bash
   date
   ls -ltr
6. **Wait until the specified time (4:32 PM) for the cron job to execute , then:**
   ```bash
   ls -ltr
   #newfile is created 
   






