# setup.py
from setuptools import setup, Extension
from Cython.Build import cythonize

ext = Extension(name="esa", 
                sources=["esa.pyx"], 
                language="c++",  # <-- この行を追加
                extra_compile_args=["-std=c++11"])  # C++11モードでコンパイル

setup(
    name="esaxx-py",  # パッケージ名
    version="0.1.0",  # バージョン情報
    author="Your Name",  # あなたの名前
    author_email="your.email@example.com",  # あなたのメール
    description="A short description about your package",  # 短い説明
    long_description=open("README.md", "r", encoding="utf-8").read(),  # ロングディスクリプション
    long_description_content_type="text/markdown",  # READMEの形式
    url="https://github.com/yusuke1997/esaxx-py",  # リポジトリのURL
    classifiers=[  # クラス分類子
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.7',  # 必要なPythonのバージョン
    install_requires=[
        "cython",
        # その他の依存関係
    ],
    ext_modules=cythonize(ext)
)
