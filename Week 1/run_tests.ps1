param($exe, $total, $folder="tests")
for ($i = 1; $i -le $total; $i++) {
    Get-Content "$folder\$i.in" | & $exe > my.out
    $result = diff (Get-Content my.out) (Get-Content "$folder\$i.out")
    if ($result -eq $null) {
        Write-Host "Test $i PASSED" -ForegroundColor Green
    } else {
        Write-Host "Test $i FAILED" -ForegroundColor Red
    }
}