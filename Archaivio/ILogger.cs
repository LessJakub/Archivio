public class ILogger
{
    private static ILogger instance = new ILogger();

    public ILogger() 
    {
#if DEBUG
    std::count << "Created instance of logger \n";
#endif
    }

    public:
        virtual void Log(std::string message);

        virtual void Error(std::string message);
}