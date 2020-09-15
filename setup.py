import setuptools
import pathlib

with open("README.md", "r") as fh:
    long_description = fh.read()


setuptools.setup(
    name="sourcehold",
    version="0.0.2",
    author="The developers",
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
    data_files={
        "sourcehold": [str(p) for p in (list(pathlib.Path().glob("*.dll")) + list(pathlib.Path().glob("*.so"))) if p.is_file()],
        "sourcehold/cheatengine": [str(p) for p in (list(pathlib.Path("cheatengine").rglob("*.CT"))) if p.is_file()],
        "sourcehold/resources": [str(p) for p in (list(pathlib.Path("resources").rglob("*.map")) + list(pathlib.Path("resources").rglob("*.sav")) + list(pathlib.Path("resources").rglob("*.msv"))) if p.is_file()],
        "sourcehold/structure": [str(p) for p in (list(pathlib.Path("structure").rglob("*"))) if p.is_file()],
        "sourcehold/examples": [str(p) for p in (list(pathlib.Path("examples").rglob("*.py"))) if p.is_file()],
        "sourcehold/tests": [str(p) for p in (list(pathlib.Path("tests").rglob("*.py"))) if p.is_file()]
    }.items(),
    install_requires=["pymem", "Pillow", "plotly"],
    test_suite="tests",
    entry_points={
        'console_scripts': ['sourcehold=sourcehold:entry_point']
    }
)
