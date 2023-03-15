// See https://aka.ms/new-console-template for more information

static int Transfrom(int previous)
{
    //if previous is an odd number
    if ((previous & 1) == 1)
        return 3 * previous + 1;

    return previous >> 1;
}

static List<int> GetSeries(int number)
{
    var result = new List<int>();
    result.Add(number);
    while (number != 1)
    {
        number = Transfrom(number);
        result.Add(number);
    }

    return result;
}

static string SeriesToString(List<int> numbers)
{
    return $"[{String.Join(", ", numbers.Select(numbers => numbers.ToString()))}]";
}

var numbers = GetSeries(1025);
var strToPrint = SeriesToString(numbers);
Console.WriteLine(strToPrint);
