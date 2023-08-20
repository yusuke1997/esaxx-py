# setup.py
from setuptools import setup, Extension
from Cython.Build import cythonize

ext = Extension(name="esa", 
                sources=["esa.pyx"], 
                language="c++",  # <-- この行を追加
                extra_compile_args=["-std=c++11"])  # C++11モードでコンパイル

setup(
    ext_modules=cythonize(ext)
)
