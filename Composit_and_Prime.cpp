/*
    QUESTION-> Given two integers L and R find the difference of number of composites and primes between the range L and R (both inclusive).

    Use  of seive eratosthenes

    T.C-> O(N LOG(N))

    S.C-> O(N)
*/
int Count(int L, int R)
{
    vector<bool> prime(R, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= R; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= R; j += i)
            {
                prime[j] = false;
            }
        }
    }
    int PrimeCount = 0;
    int CompositCount = 0;
    for (int i = L; i <= R; i++)
    {
        if (i < 2)
        {
            continue;
        }
        if (prime[i])
        {
            PrimeCount++;
        }
        else
        {
            CompositCount++;
        }
    }
    return CompositCount - PrimeCount;
}