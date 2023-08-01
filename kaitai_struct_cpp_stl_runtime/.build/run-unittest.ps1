<#
.DESCRIPTION
Runs unit tests on Windows
#>

# Standard boilerplate
Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
$PSDefaultParameterValues['*:ErrorAction']='Stop'

# Go to repo root
$repoRoot = (Resolve-Path "$PSScriptRoot\..").Path
Push-Location $repoRoot

cd build

# Use ctest
#ctest -C Debug --output-on-failure

# Run gtest-generated binary directly, produces more detailed output
./tests/Debug/unittest.exe

Pop-Location
