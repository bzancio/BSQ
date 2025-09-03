#!/bin/bash
# runner.sh - ejecuta ./bsq sobre todos los mapas de bsq_tests
# uso: ./runner.sh ./bsq

BIN="$1"
TESTDIR="bsq_tests"

if [ -z "$BIN" ]; then
    echo "Uso: $0 ./bsq"
    exit 1
fi

if [ ! -x "$BIN" ]; then
    echo "Error: $BIN no existe o no es ejecutable"
    exit 1
fi

for f in "$TESTDIR"/*; do
    if [ -f "$f" ] && [[ "$f" != *.md ]]; then
        echo ">>> Probando $f"
        # Capturamos stderr
        ERR=$("$BIN" "$f" 2>&1 >/dev/null)
        if echo "$ERR" | grep -q "map error"; then
            echo "Resultado: INVALID (map error detectado)"
        else
            echo "Resultado: VALID (no se detectó error)"
        fi
        echo
    fi
done
