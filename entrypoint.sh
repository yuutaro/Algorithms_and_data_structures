#!/bin/sh
set -e

# ユーザーとグループの作成
USERID=${LOCAL_USER_ID:-1000}
GROUPID=${LOCAL_GROUP_ID:-1000}

addgroup -g $GROUPID dcuser || true
adduser -D -H -u $USERID -G dcuser dcuser || true

# /workspace ディレクトリの所有者を dcuser に変更
chown -R dcuser:dcuser /workspace

# 実行するコマンドを表示
echo "Executing command: $@"

# dcuser としてコマンドを実行
exec su-exec dcuser "$@"