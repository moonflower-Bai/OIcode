#!/bin/bash

# 默认关闭调试模式
DEBUG_MODE=0

# 解析命令行参数
while getopts ":d" opt; do
    case $opt in
        d)
            DEBUG_MODE=1
            echo "Debug mode enabled."
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
    esac
done

# 调试函数
debug() {
    if [ "$DEBUG_MODE" -eq 1 ]; then
        echo "[DEBUG] $1"
    fi
}

function getdir() {
    local dir="$1"
    debug "Processing directory: $dir"

    for element in $(ls -A "$dir")  # 使用 ls -A 避免列出 . 和 ..
    do  
        local dir_or_file="$dir/$element"
        
        # 跳过符号链接
        if [ -L "$dir_or_file" ]; then
            debug "Skipping symbolic link: $dir_or_file"
            continue
        fi

        if [ -d "$dir_or_file" ]; then
            # 忽略当前目录和上级目录
            if [[ "$element" == "." || "$element" == ".." || "$element" == ".git" ]]; then
                debug "Skipping special directory: $dir_or_file"
                continue
            fi
            # 检查是否为 .cph 目录
            if [[ "$element" == ".cph" ]]; then
                debug "Removing directory: $dir_or_file"
                rm -rf "$dir_or_file"
            else
                # 递归处理子目录
                getdir "$dir_or_file"
            fi
        else
            # 检查是否为 ELF 文件
            if file "$dir_or_file" | grep -q "ELF"; then
                debug "Removing ELF file: $dir_or_file"
                rm -f "$dir_or_file"
            fi
        fi  
    done
}

# 主程序入口
root_dir="/home/moonflowerr/Code"

# 移除已解析的选项，保留剩余参数
shift $((OPTIND - 1))

# 如果提供了根目录参数，则覆盖默认值
if [ -n "$1" ]; then
    root_dir="$1"
fi

getdir "$root_dir"