import subprocess

# logging.basicConfig(level = logging.DEBUG)

subprocess.run(["python", "-m", "unittest", "discover"]).check_returncode()
