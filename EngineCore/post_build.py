import os
import sys

def main(build_dir):
    shared_libs_dir = os.path.join("../shared_libs")

    print("--------------------------------------------------")
    print("Beginning post_build.py script for EngineCore...")
    print("--------------------------------------------------")

    print(f"Creating shared_libs directory at {shared_libs_dir}...")
    os.makedirs(shared_libs_dir, exist_ok=True)

    engine_core_dll = os.path.join(build_dir, "EngineCore.dll")
    fmt_dll = os.path.join(build_dir, "fmt.dll")
    spdlog_dll = os.path.join(build_dir, "spdlog.dll")
    glfw3_dll = os.path.join(build_dir, "glfw3.dll")

    fmtd_dll = os.path.join(build_dir, "fmtd.dll")
    spdlogd_dll = os.path.join(build_dir, "spdlogd.dll")

    print(f"Copying from {engine_core_dll} to {shared_libs_dir}...")
    os.system(f'copy "{engine_core_dll}" "{shared_libs_dir}"')

    print(f"Copying from {fmt_dll} to {shared_libs_dir}...")
    os.system(f'copy "{fmt_dll}" "{shared_libs_dir}"')

    print(f"Copying from {spdlog_dll} to {shared_libs_dir}...")
    os.system(f'copy "{spdlog_dll}" "{shared_libs_dir}"')

    print(f"Copying from {glfw3_dll} to {shared_libs_dir}...")
    os.system(f'copy "{glfw3_dll}" "{shared_libs_dir}"')

    print(f"Copying from {fmtd_dll} to {shared_libs_dir}...")
    os.system(f'copy "{fmtd_dll}" "{shared_libs_dir}"')

    print(f"Copying from {spdlogd_dll} to {shared_libs_dir}...")
    os.system(f'copy "{spdlogd_dll}" "{shared_libs_dir}"')

    print("--------------------------------------------------")
    print("Ending post_build.py script for EngineCore...")
    print("--------------------------------------------------")

if __name__ == "__main__":
    main(sys.argv[1])
