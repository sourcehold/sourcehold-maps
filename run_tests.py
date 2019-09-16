import subprocess

subprocess.run(["python", "-m", "unittest", "discover"]).check_returncode()
