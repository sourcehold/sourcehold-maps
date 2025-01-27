import setuptools

from setuptools import setup

with open("README.md", "r") as fh:
    long_description = fh.read()

setup(
    name="sourcehold",
    version="1.0.1",
    author="Gynt",
    author_email="gynt@users.noreply.github.com",
    description="A package to interact with stronghold (crusader) files and the process",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/sourcehold/sourcehold-maps",
    packages=setuptools.find_packages(include=("sourcehold", "sourcehold.*")),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.8',
    install_requires=["pymem", "Pillow", "dclimplode", "numpy"],
    test_suite="tests",
    entry_points={
        'console_scripts': ['sourcehold=sourcehold:entry_point']
    }
)
