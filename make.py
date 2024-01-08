import os
import subprocess
from pathlib import Path

def translate_binding(project_name, bindfiles, compile_args, languages):
    if not bindfiles:
        raise ValueError("BINDFILES is a required argument")

    target_name = f"{project_name}-c"

    # Resolve absolute paths for bindfiles
    bindfile_abs_args = [str(Path(bindfile).resolve()) for bindfile in bindfiles]
    languages_str = " ".join(f"-l{lang}" for lang in set(languages))

    babble_translate = "./install/bin/bbl-translate"
    babble_resource_dir = "install"
    include_dirs = ["install/include"]
    
    cmd = [
        babble_translate,
        *bindfile_abs_args,
        '--',
        '-std=c++17',
        '-fsyntax-only',
        '-fno-spell-checking',
        *[f'-I{babble_resource_dir}/include'] + [f'-I{dir}' for dir in include_dirs],
        *compile_args,
        '--',
        project_name,
        '-o', str(Path.cwd()),
        languages_str
    ]
    
    # Ensure correct spacing and quoting.
    print("Executing command:", ' '.join(cmd))  # Just to debug and see the command before execution
    subprocess.run(' '.join(cmd), shell=True, check=True)

# Usage example
translate_binding(
    project_name="bbl-usd",
    bindfiles=[
        "bind/ar.cpp",
        "bind/gf.cpp",
        "bind/js.cpp",
        "bind/ndr.cpp",
        "bind/pcp.cpp",
        "bind/sdf.cpp",
        "bind/sdr.cpp",
        "bind/std.cpp",
        "bind/tf.cpp",
        "bind/usd.cpp",
        "bind/usdGeom.cpp",
        "bind/vt.cpp",
    ],
    compile_args=[
        "-Wno-deprecated-builtins",
        "-Wno-#pragma-messages",
        "-DNOMINMAX",
        "-D_MT",
        "-DBOOST_ALL_NO_LIB",
        "-D__TBB_show_deprecation_message_task_H",
    ],
    languages=["C", "CXX"],
)
