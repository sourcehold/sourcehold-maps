import setuptools
import pathlib

from Cython.Build import cythonize
from distutils.extension import Extension
from setuptools import setup

from Cython.Distutils import build_ext


with open("README.md", "r") as fh:
    long_description = fh.read()

ext_modules = cythonize([
    Extension(
        'sourcehold.compression.compressionlib',
        ['compression/cppklib.pyx', 'compression/buffers.cpp', 'compression/explode.c', 'compression/implode.c',
         'compression/crc32.c'],
        language='c++'
    )
])

setup(
    name="sourcehold",
    cmdclass={"build_ext": build_ext},
    version="0.0.3",
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
    package_data={
        "sourcehold": ["debugtools/memory/common/access/*.ct"],
    },
    install_requires=["pymem", "Pillow"],
    test_suite="tests",
    entry_points={
        'console_scripts': ['sourcehold=sourcehold:entry_point', 'srchold=sourcehold:entry_point']
    },
    ext_modules=ext_modules
)
