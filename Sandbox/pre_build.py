import os
import sys

def main(build_dir):
    shared_libs_dir = os.path.join("../shared_libs")

    print("--------------------------------------------------")
    print("Beginning pre_build.py script for Sandbox...")
    print("--------------------------------------------------")

    print(f"Creating shared_libs directory at {shared_libs_dir}...")
    os.makedirs(shared_libs_dir, exist_ok=True)

    engine_core_dll = os.path.join(shared_libs_dir, "EngineCore.dll")
    fmt_dll = os.path.join(shared_libs_dir, "fmtd.dll")
    spdlog_dll = os.path.join(shared_libs_dir, "fmtd.dll")
    glfw3_dll = os.path.join(shared_libs_dir, "fmtd.dll")

    fmtd_dll = os.path.join(shared_libs_dir, "fmtd.dll")
    spdlogd_dll = os.path.join(shared_libs_dir, "fmtd.dll")

    print(f"Copying from {engine_core_dll} to {build_dir}...")
    os.system(f'copy "{engine_core_dll}" "{build_dir}"')

    print(f"Copying from {fmt_dll} to {build_dir}...")
    os.system(f'copy "{fmt_dll}" "{build_dir}"')

    print(f"Copying from {spdlog_dll} to {build_dir}...")
    os.system(f'copy "{spdlog_dll}" "{build_dir}"')

    print(f"Copying from {glfw3_dll} to {build_dir}...")
    os.system(f'copy "{glfw3_dll}" "{build_dir}"')

    print(f"Copying from {fmtd_dll} to {build_dir}...")
    os.system(f'copy "{fmtd_dll}" "{build_dir}"')

    print(f"Copying from {spdlogd_dll} to {build_dir}...")
    os.system(f'copy "{spdlogd_dll}" "{build_dir}"')

    print("--------------------------------------------------")
    print("Ending post_build.py script for Sandbox...")
    print("--------------------------------------------------")

if __name__ == "__main__":
    main(sys.argv[1])
