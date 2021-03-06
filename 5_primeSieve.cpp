/* Generate a prime list from 0 up to n, using The Sieve of Erantosthenes
param n The upper bound of the prime list (including n)
param prime[] An array of truth value whether a number is prime
*/
void prime_sieve(int n, bool prime[]) {
  prime[0] = false;
  prime[1] = false;
  int i;
  for (i = 2; i <= n; i++)
    prime[i] = true;
 
  int limit = sqrt(n);
  for (i = 2; i <= limit; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i)
        prime[j] = false;
    }
  }
}