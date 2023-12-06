import subprocess

# Getting metadata for Wi-Fi profiles
meta_data = subprocess.check_output(['netsh', 'wlan', 'show', 'profiles'])

# Decoding metadata
data = meta_data.decode('utf-8', errors="backslashreplace")

# Splitting data by line
data = data.split('\n')

# Creating a list of profiles
profiles = []

# Traverse the data
for line in data:
    if "All User Profile" in line:
        profile_name = line.split(":")[1].strip()
        profiles.append(profile_name)

# Printing heading
print("{:<30}| {:<}".format("Wi-Fi Name", "Password"))
print("----------------------------------------------")

# Traverse the profiles
for profile in profiles:
    try:
        # Get metadata with password using the Wi-Fi profile name
        results = subprocess.check_output(['netsh', 'wlan', 'show', 'profile', profile, 'key=clear'])

        # Decode and split data line by line
        results = results.decode('utf-8', errors="backslashreplace")
        results = results.split('\n')

        # Find password from the result list
        password = [line.split(":")[1].strip() for line in results if "Key Content" in line]

        # Print Wi-Fi name and password if found
        if password:
            print("{:<30}| {:<}".format(profile, password[0]))
        else:
            print("{:<30}| {:<}".format(profile, "Password not found"))

    except subprocess.CalledProcessError as e:
        print(f"Error occurred for {profile}: {str(e)}")
