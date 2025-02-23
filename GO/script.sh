#!/bin/bash

go test -coverprofile=coverage.out ./tree -v
mkdir -p coverage_html

go tool cover -html=coverage.out -o index.html
mv coverage.out index.html coverage_html/


mkdir -p ser
go build -o ser/main main.go