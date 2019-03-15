# input the data from csv
hgate1 <- read.csv(file = "C:/Users/Joey/Desktop/TestData/DCSine/Data From DC Sine/Trial8/HGate.csv", FALSE)
hgate2 <- read.csv(file = "C:/Users/Joey/Desktop/TestData/DCSine/Data From DC Sine/Trial6/HGate.csv", FALSE)
mgate1 <- read.csv(file = "C:/Users/Joey/Desktop/TestData/DCSine/Data From DC Sine/Trial8/MGate.csv", FALSE)
mgate2 <- read.csv(file = "C:/Users/Joey/Desktop/TestData/DCSine/Data From DC Sine/Trial6/MGate.csv", FALSE)
ngate1 <- read.csv(file = "C:/Users/Joey/Desktop/TestData/DCSine/Data From DC Sine/Trial8/NGate.csv", FALSE)
ngate2 <- read.csv(file = "C:/Users/Joey/Desktop/TestData/DCSine/Data From DC Sine/Trial6/NGate.csv", FALSE)

# load packages
#install.packages("Rcpp")
suppressWarnings(
    if (!require("ggplot2", quietly = TRUE))
        install.packages("ggplot2", quiet = TRUE))

suppressWarnings(
    if (!require("gapminder", quietly = TRUE))
        install.packages("gapminder", quiet = TRUE))

suppressWarnings(
    if (!require("reshape2", quietly = TRUE))
        install.packages("reshape2", quiet = TRUE))

library("ggplot2", quietly = TRUE)
library("gapminder", quietly = TRUE)
library("reshape2", quietly = TRUE)


# The following will create a set of plots, each being the specified data at multiple time points
numValuesPerTime <- ncol(hgate1) - 2    # set the time values
x <- 2:numValuesPerTime                 # create list of numbers used for nodes
data <- hgate1                          # set the data being used
for (num in c(4000, 4100, 4200, 4300, 4400, 4500, 4600, 4700, 4800, 4900)) {    # loop through a set of times
    y <- data[num, x]   # read data row, which is the values at a specific time
    y <- t(y)           # transpose y to be a vertical vector
    y <- unname(y)      # unname so that it can be named when making the dataframe
    dataFrameNew <- data.frame("NODE" = x, "HGate" = y) # create the dataframe
    print(head(dataFrameNew))                           # output the dataframe head
    p4 <- ggplot(dataFrameNew, aes(NODE, HGate)) + geom_point(color = 'BLUE') +
            coord_cartesian(ylim = c(0, 1)) +
            ggtitle(paste('H Gate @ Time = ', data[num, 1], 'ms'))  # make basic plot
    print(p4)   # neet to print the plot because it is within a for loop
}


# Convert csv data to a more useful data frame
# change 'ngate2' on the line below to whatever data from csv you want
tempData <- ngate2  
times <- tempData[1:nrow(tempData), 1] # read the times listed in the first column
tempDF <- data.frame("Time" = times) # Make the dataframe, with just the time data
names(tempDF)[1] <- "Time" # Title the name of the time data
for (num in 2:(ncol(tempData) - 1)) {
    # loop through every column of the data (which is every node)
    tempDF <- cbind(tempDF, NODE = tempData[1:nrow(tempData), num]) # add the next column of the data to the data frame
    names(tempDF)[num] <- paste("Node", num - 1, sep = "") # label the new column ("Node<num>")
}
# change 'ngate2DF' to where you would like to store the new dataframe
ngate2DF <- tempDF


# Plotting m^3 * h
m3h1DF <- data.frame("Time" = times)
for (num in 2:(ncol(data) - 1)) {
    # loop through every column of the data (which is every node)
    m3h1DF <- cbind(m3h1DF, NODE = mgate1[1:nrow(mgate1), num] ^ 3 * hgate1[1:nrow(hgate1), num]) # add the next column of the data to the data frame
    names(m3h1DF)[num] <- paste("Node", num - 1, sep = "") # label the new column ("Node<num>")
}
ggplot(m3h1DF, aes(Time, Node50)) + geom_point(color = "#999922")


# Increase text size
theme_update(text = element_text(size = 20))


# Plot m and h on top of eachother
ggplot(mgate1DF, aes(Time, Node50)) + geom_point(color = "#33FF66") + geom_point(data = hgate1DF, aes(Time, Node50), color = "#3333CC") + ggtitle("MGATE 1 Node 50") # sample plot
p <- ggplot(mgate1DF, aes(Time, Node50)) + geom_point(color = "#33FF66") + geom_point(data = hgate1DF, aes(Time, Node50), color = "#3333CC") + ggtitle("M and H Gate Node 50") + labs(x = "Time (ms)", y = "Gate Value")


# Plot m from two different nodes
ggplot(mgate2DF, aes(Time, Node50)) + geom_point(color = "#11FF11") + geom_point(data = mgate2DF, aes(Time, Node49), color = "#EE1122") + ggtitle("Trial6 MGate nodes 50 and 49")


# Plot m and h from two different trials
ggplot(mgate1DF, aes(Time, Node50)) + geom_point(color = "#33FF66") + geom_point(data = mgate2DF, aes(Time, Node50), color = "#3333CC") +geom_point(data =hgate1DF, aes(Time, Node50),color = "#33FF66") + geom_point(data = hgate2DF, aes(Time, Node50), color = "#3333CC") + ggtitle("Trial7 and Trial 5")