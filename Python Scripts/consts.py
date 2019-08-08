""" Defines basic constants for python scripts in this repo"""
import os

# Kinda ugly, we get the path to this script via dirname and __file__. we then
# join ".." to get one level up and use `abspath` to simplify the path for us
# and make it absolute
REPO_ROOT_FOLDER = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
PY_SCRIPTS_FOLDER = os.path.join(REPO_ROOT_FOLDER, "Python Scripts")
