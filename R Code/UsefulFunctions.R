# x: the vector
# n: the number of samples
# centered: if FALSE, then average current sample and previous (n-1) samples
#           if TRUE, then average symmetrically in past and future. (If n is even, use one more sample from future.)
movingAverage <- function(x, n = 1, centered = FALSE) {
  if (centered) {
    before <- floor((n - 1) / 2)
    after <- ceiling((n - 1) / 2)
  } else {
    before <- n - 1
    after <- 0
  }
  # Track the sum and count of number of non-NA items
  s <- rep(0, length(x))
  count <- rep(0, length(x))
  # Add the centered data 
  new <- x
  # Add to count list wherever there isn't a 
  count <- count + !is.na(new)
  # Now replace NA_s with 0_s and add to total
  new[is.na(new)] <- 0
  s <- s + new
  # Add the data from before
  i <- 1
  while (i <= before) {
    # This is the vector with offset values to add
    new <- c(rep(NA, i), x[1:(length(x) - i)])
    
    count <- count + !is.na(new)
    new[is.na(new)] <- 0
    s <- s + new
    
    i <- i + 1
  }
  # Add the data from after
  i <- 1
  while (i <= after) {
    # This is the vector with offset values to add
    new <- c(x[(i + 1):length(x)], rep(NA, i))
    count <- count + !is.na(new)
    new[is.na(new)] <- 0
    s <- s + new
    i <- i + 1
  }
  # return sum divided by count
  s / count
}

movingAverageDF <- function(df, n) {
  newDF <- df
  for (name in colnames(df)) {
    if (!identical(name, "Time")) {
      # loop through every column of the data (which is every node)
      newDF[[name]] <- movingAverage(df[[name]], n, FALSE) # find the moving average
      #names(newDF)[name] <- paste(name) # label the new column ("Node<num>")
    }
  }
  newDF
}

slopeDF <- function(df, collumns) {
  newDF <- df
  for (name in collumns) {
    if (!identical(name, "Time")) {
      # loop through every column of the data (which is every node)
      for (row in 2:nrow(df)) {
        
        newDF[row, name] = (df[row, name] - df[row - 1, name])
      }
    }
  }
  newDF
}

csvToDF <- function(csv){
  tempData <- csv
  times <- tempData[1:nrow(tempData), 1] # read the times listed in the first column
  tempDF <- data.frame("Time" = times) # Make the dataframe, with just the time data
  names(tempDF)[1] <- "Time" # Title the name of the time data
  for (num in 2:(ncol(tempData) - 1)) {
    # loop through every column of the data (which is every node)
    tempDF <- cbind(tempDF, NODE = tempData[1:nrow(tempData), num]) # add the next column of the data to the data frame
    names(tempDF)[num] <- paste("Node", num - 1, sep = "") # label the new column ("Node<num>")
  }
  tempDF
}

m3hCalcDF <- function(tempm, temph){
  times <- temph[1:nrow(temph), 1] # read the times listed in the first column
  tempmhDF <- data.frame("Time" = times)
  for (num in 2:(ncol(tempm) - 1)) {
    # loop through every column of the data (which is every node)
    tempmhDF <- cbind(tempmhDF, NODE = tempm[1:nrow(tempm), num] ^ 3 * temph[1:nrow(temph), num]) # add the next column of the data to the data frame
    names(tempmhDF)[num] <- paste("Node", num - 1, sep = "") # label the new column ("Node<num>")
  }
  tempmhDF
}

gate4CalcDF <- function(tempDF){
  times <- tempDF[1:nrow(tempDF), 1]
  temp4DF <- data.frame("Time" = times)
  for (num in 2:(ncol(tempDF) - 1)){
    temp4DF <- cbind(temp4DF, NODE = tempDF[1:nrow(tempDF), num] ^ 4)
    names(temp4DF)[num] <- paste("Node", num-1, sep="")
  }
  temp4DF
}

# plot the center node and nodes to the left of center on a single plot
plotMultipleNodes <- function(df, title, xmin, xmax, ymin, ymax){
  tempDF <- df
  ggplot(data = tempDF, aes(Time, Node51)) + geom_line(color = "#55FF44", size = 2) +
    geom_line(data = tempDF, aes(Time, Node42), color = "#4400FF", size = 2) +
    geom_line(data = tempDF, aes(Time, Node43), color = "#4400BB", size = 2) +
    geom_line(data = tempDF, aes(Time, Node44), color = "#110088", size = 2) +
    geom_line(data = tempDF, aes(Time, Node45), color = "#110044", size = 2) +
    geom_line(data = tempDF, aes(Time, Node46), color = "#000000", size = 2) +
    geom_line(data = tempDF, aes(Time, Node47), color = "#440000", size = 2) +
    geom_line(data = tempDF, aes(Time, Node48), color = "#990000", size = 2) +
    geom_line(data = tempDF, aes(Time, Node49), color = "#CC4444", size = 2) +
    geom_line(data = tempDF, aes(Time, Node50), color = "#FF8888", size = 2) +
    ggtitle(title) +
    xlim(xmin,xmax) +
    ylim(ymin,ymax)
}

buildAllDF <- function(mDF, hDF, sDF, mpDF, vDF){
    times <- mDF[1:nrow(mDF), 1]
    tempAllDF <- data.frame("Time" = times)
    for (num in 2:(ncol(mDF))){
      tempAllDF <- cbind(tempAllDF, NODE = mDF[1:nrow(mDF), num])
      names(tempAllDF)[num] <- paste("M", num-1, sep="")
    }
    for (num in 2:(ncol(hDF))){
      tempAllDF <- cbind(tempAllDF, NODE = hDF[1:nrow(hDF), num])
      names(tempAllDF)[num+101] <- paste("H", num-1, sep="")
    }
    for (num in 2:(ncol(vDF))){
      tempAllDF <- cbind(tempAllDF, NODE = vDF[1:nrow(vDF), num])
      names(tempAllDF)[num+202] <- paste("V", num-1, sep="")
    }
    for (num in 2:(ncol(sDF))){
      tempAllDF <- cbind(tempAllDF, NODE = sDF[1:nrow(sDF), num])
      names(tempAllDF)[num+303] <- paste("S", num-1, sep="")
    }
    for (num in 2:(ncol(mpDF))){
      tempAllDF <- cbind(tempAllDF, NODE = mpDF[1:nrow(mpDF), num])
      names(tempAllDF)[num+404] <- paste("MP", num-1, sep="")
    }
    tempAllDF
}

getDataAllDF <- function(folderPath){
  print("Collecting M Gate")
  tempm <- read.csv(file = paste(folderPath, "MGate.csv", sep = ""), FALSE)
  print("Collecting H Gate")
  temph <- read.csv(file = paste(folderPath, "HGate.csv", sep = ""), FALSE)
  print("Collecting S Gate")
  temps <- read.csv(file = paste(folderPath, "SGate.csv", sep = ""), FALSE)
  print("Collecting MP Gate")
  tempmp <- read.csv(file = paste(folderPath, "MPGate.csv", sep = ""), FALSE)
  print("Collecting Voltage")
  tempv <- read.csv(file = paste(folderPath, "Voltage.csv", sep = ""), FALSE)
  
  print("Converting to Data Frames")
  tempmDF <- csvToDF(tempm)
  temphDF <- csvToDF(temph)
  tempsDF <- csvToDF(temps)
  tempmpDF <- csvToDF(tempmp)
  tempvDF <- csvToDF(tempv)
  
  print("Combining Data Frames")
  allDF <- buildAllDF(tempmDF, temphDF, tempsDF, tempmpDF, tempvDF)
  print("Done")
  allDF
}