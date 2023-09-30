import { test, expect } from '@playwright/test'
const start = 193838910

const url = 'https://codeforces.com/contest/1795/submission/'

while (start <= 193908451) {}

test('get started link', async ({ page }) => {
  await page.goto('https://playwright.dev/')

  // Click the get started link.
  await page.getByRole('link', { name: 'Get started' }).click()

  // Expects the URL to contain intro.
  await expect(page).toHaveURL(/.*intro/)
})

for(int i = 0;i<n;i++){
  
}